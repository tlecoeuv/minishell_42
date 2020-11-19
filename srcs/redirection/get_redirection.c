/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 23:31:02 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/11/19 11:27:22 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	get_redir(t_token **lst_token, t_cmd *cmd)
{
	t_token		*tmp;
	int			check;

	cmd->in_fd = 0;
	cmd->out_fd = 0;
	tmp = *lst_token;
	check = 0;
	while (tmp && tmp->type != pip && tmp->type != end)
	{
		if (tmp->type <= 3)
			get_and_delete(&tmp, lst_token, cmd, check);
		else
			tmp = tmp->next;
		check = 1;
	}
}

void	get_and_delete(t_token **tmp, t_token **lst_tok, t_cmd *cmd, int check)
{
	t_token		*start;
	t_token		*end;
	t_type		redir_type;

	start = *tmp;
	redir_type = (*tmp)->type;
	*tmp = (*tmp)->next;
	get_redir_fd((*tmp)->str, cmd, redir_type);
	end = *tmp;
	*tmp = (*tmp)->next;
	if (check != 0)
		del_start_to_end(lst_tok, start, end);
	else
		while (*lst_tok && *lst_tok != *tmp)
			*lst_tok = (*lst_tok)->next;
}

void	get_redir_fd(char *file, t_cmd *cmd, t_type redir_type)
{
	int		fd;

	fd = open_redir_fd(file, redir_type);
	if (fd == -1)
	{
		error(NULL, file);
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

int		open_redir_fd(char *file, t_type redir_type)
{
	int		fd;

	fd = 0;
	if (redir_type == out)
		fd = open(file, O_TRUNC | O_WRONLY | O_CREAT, 0664);
	else if (redir_type == append_out)
		fd = open(file, O_APPEND | O_WRONLY | O_CREAT, 0664);
	else if (redir_type == in)
		fd = open(file, O_RDONLY);
	return (fd);
}
