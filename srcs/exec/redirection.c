/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 23:31:02 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/10/26 11:56:53 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void 			get_redir_and_fd(t_token **lst_token, t_cmd *cmd)
{
	cmd->redir_fd = 0;

	if (!(*lst_token) || (*lst_token)->type == end)
		cmd->redir_type = nope;
	else
	{
		while(*lst_token && (*lst_token)->type <= 3
							&& (*lst_token)->type != pip && cmd->redir_fd != -1)
		{
			cmd->redir_type = (*lst_token)->type;
			*lst_token = (*lst_token)->next;
			if ((*lst_token)->type == space)
				*lst_token = (*lst_token)->next;
			get_redir_fd((*lst_token)->str, cmd);
			*lst_token = (*lst_token)->next;
			if ((*lst_token) && (*lst_token)->type == space)
				*lst_token = (*lst_token)->next;
		}
	}
	if (cmd->redir_fd == -1)
		skip_redir(lst_token);
}

void			get_redir_fd(char *file, t_cmd *cmd)
{
	int		fd;

	fd = 0;
	if (cmd->redir_fd > 0)
		close(cmd->redir_fd);
	if (cmd->redir_type == out)
		fd = open(file, O_TRUNC | O_WRONLY | O_CREAT, 0664);
	else if (cmd->redir_type == append_out)
		fd = open(file, O_APPEND | O_WRONLY | O_CREAT, 0664);
	else if (cmd->redir_type == in)
		fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		error(cmd->args[0], file);
		g_sh.status = 1;
	}
	cmd->redir_fd = fd;
}

void			do_redir(t_type redir_type, int fd)
{
	if (redir_type == out || redir_type == append_out)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	else if (redir_type == in)
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
}
