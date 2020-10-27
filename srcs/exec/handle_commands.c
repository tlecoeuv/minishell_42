/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 14:33:56 by tanguy            #+#    #+#             */
/*   Updated: 2020/10/27 08:34:24 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		spawn_process(int in, int out, int to_close,t_cmd *cmd)
{
	pid_t pid;

 	if ((pid = fork ()) == 0)
    {
		close(to_close);
		if (in != 0)
        {
 			dup2 (in, STDIN_FILENO);
			close (in);
        }
		if (out != 1)
		{
			dup2 (out, STDOUT_FILENO);
			close (out);
        }
		handle_one_command(cmd);
	}
}

void		handle_commands_pipe(t_cmd **cmds, int nb_cmds)
{
	int		i;
 	int		in;
	pid_t	pid;
  	int		pipefd[2];

	in = 0;
	i = 0;
	while (i < nb_cmds - 1)
	{
		pipe(pipefd);
		spawn_process(in, pipefd[WRITE_END], pipefd[READ_END], cmds[i]);
		close(pipefd[WRITE_END]);
		in = pipefd[READ_END];
		i++;
	}
	pid = fork();
	if (pid < 0)
		perror("fork");
	else if (pid > 0)
		while(wait(NULL) != -1 && errno != ECHILD);
	else
	{
		if (in != 0)
			dup2 (in, STDIN_FILENO);
		handle_one_command(cmds[i]);
	}
}

void		handle_one_command(t_cmd *cmd)
{
	if (cmd->redir_fd != -1)
	{
		if (is_builtin(cmd->args[0]))
		{
			exec_builtin(cmd);
			exit(0);
		}
		else
		{
			if (!get_absolute_path(cmd->args))
				error_cmd_not_found(cmd->args[0]);
			else
			{
				do_redir(cmd->redir_type, cmd->redir_fd);
				if (execve(cmd->args[0], cmd->args, g_sh.env) == -1)
					exit(EXIT_FAILURE);
			}
		}
		if (cmd->redir_type != nope)
			close(cmd->redir_fd);
	}
}
