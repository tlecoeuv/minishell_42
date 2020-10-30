/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:18:26 by tanguy            #+#    #+#             */
/*   Updated: 2020/10/30 13:27:56 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		handle_tokens(t_token *lst_token)
{
	t_cmd	**cmds;
	int		i;
	int		nb_cmds;

	i = 0;
	while (lst_token)
	{
		cmds = get_commands(&lst_token, &nb_cmds);
		if (nb_cmds == 1)
			handle_command_no_pipe(cmds[0]);
		else
			handle_commands_pipe(cmds, nb_cmds);
		while(cmds[i])
		{
			free_array(cmds[i]->args);
			free(cmds[i]);
			i++;
		}
		free(cmds);
	}
}

void		handle_command_no_pipe(t_cmd *cmd)
{
	if (cmd->out_fd != -1 && cmd->in_fd != -1)
	{
		if (is_builtin(cmd->args[0]))
			exec_builtin(cmd);
		else
		{
			if (!get_absolute_path(cmd->args))
				error_cmd_not_found(cmd->args[0]);
			else
				exec_cmd(cmd);
		}
	}
}

void		exec_cmd(t_cmd *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		perror("fork");
	else if (pid > 0)
		while(wait(NULL) != -1 && errno != ECHILD);
	else
	{
		do_redir(cmd->in_fd, cmd->out_fd);
		if (execve(cmd->args[0], cmd->args, g_sh.env) == -1)
			exit(EXIT_FAILURE);
	}
	if (cmd->out_fd > 0)
		close(cmd->out_fd);
	if (cmd->in_fd > 0)
		close(cmd->in_fd);
}
