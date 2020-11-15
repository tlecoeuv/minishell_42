/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_command_no_pipe.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 10:35:12 by tanguy            #+#    #+#             */
/*   Updated: 2020/11/15 12:44:52 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		handle_command_no_pipe(t_cmd *cmd)
{
	if (cmd->out_fd != -1 && cmd->in_fd != -1)
	{
		if (is_builtin(cmd->args[0]))
			exec_builtin(cmd);
		else
		{
			if (get_exec_path(cmd->args))
				exec_cmd(cmd);
		}
	}
}

void		exec_cmd(t_cmd *cmd)
{
	int		status;

	g_sig.pid = fork();
	if (g_sig.pid > 0)
	{
		while (wait(&status) > 0)
			;
		if (g_sig.sigint == 0 && g_sig.sigquit == 0)
			g_sh.status = WEXITSTATUS(status);
		g_sig.pid = 0;
	}
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
