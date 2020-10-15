/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 23:31:02 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/10/15 12:33:01 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void 			get_redir_and_fd(t_token **lst_token, t_cmd *cmd)
{
	if (!(*lst_token) || (*lst_token)->type == end)
		cmd->redir_type = nope;
	else
	{
		cmd->redir_type = (*lst_token)->type;
		*lst_token = (*lst_token)->next;
		if ((*lst_token)->type == space)
			*lst_token = (*lst_token)->next;
		cmd->redir_fd = get_redir_fd((*lst_token)->str, cmd->redir_type);
		*lst_token = (*lst_token)->next;
		if ((*lst_token) && (*lst_token)->type == space)
			*lst_token = (*lst_token)->next;
	}
}

int				get_redir_fd(char *file, t_type redir_type)
{
	int		fd;

	if (redir_type == out)
	{
		if ((fd = open(file, O_TRUNC | O_WRONLY | O_CREAT, 0664)) == -1)
			return (0);
	}
	else if (redir_type == append_out)
	{
		if ((fd = open(file, O_APPEND | O_WRONLY | O_CREAT, 0664)) == -1)
			return (0);
	}
	else if (redir_type == in)
	{
		if ((fd = open(file, O_RDONLY)) == -1)
			return (0);
	}
	return (fd);
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
