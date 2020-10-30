/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 23:31:02 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/10/30 17:42:30 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void 			get_redir(t_token **lst_token, t_cmd *cmd)
{
	t_type		redir_type;

	cmd->in_fd = 0;
	cmd->out_fd = 0;
	while(*lst_token && (*lst_token)->type <= 3 && (*lst_token)->type != pip
			&& cmd->out_fd != -1 && cmd->in_fd != -1)
	{
		redir_type = (*lst_token)->type;
		*lst_token = (*lst_token)->next;
		if ((*lst_token)->type == space)
			*lst_token = (*lst_token)->next;
		get_redir_fd((*lst_token)->str, cmd, redir_type);
		*lst_token = (*lst_token)->next;
		if ((*lst_token) && (*lst_token)->type == space)
			*lst_token = (*lst_token)->next;
	}
	if (cmd->out_fd == -1 || cmd->in_fd == -1)
		skip_redir(lst_token);
}

void			get_redir_fd(char *file, t_cmd *cmd, t_type redir_type)
{
	int		fd;

	fd = 0;
	if (redir_type == out)
		fd = open(file, O_TRUNC | O_WRONLY | O_CREAT, 0664);
	else if (redir_type == append_out)
		fd = open(file, O_APPEND | O_WRONLY | O_CREAT, 0664);
	else if (redir_type == in)
		fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		error(cmd->args[0], file);
		g_sh.status = 1;
	}
	if (redir_type == in)
	{
		if (cmd->in_fd > 0)
			close(cmd->in_fd);
		cmd->in_fd = fd;
	}
	else
	{
		if (cmd->out_fd > 0)
			close(cmd->out_fd);
		cmd->out_fd = fd;
	}
}
