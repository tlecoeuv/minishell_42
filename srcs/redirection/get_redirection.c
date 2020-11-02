/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 23:31:02 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/11/02 17:54:39 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*void 			get_redir(t_token **lst_token, t_cmd *cmd)
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
}*/

//si début commande on passe juste on supprime pas!

void 			get_redir(t_token **lst_token, t_cmd *cmd)
{
	t_token		*tmp;

	cmd->in_fd = 0;
	cmd->out_fd = 0;
	tmp = *lst_token;
	int		check;

	check = 0;
	while(tmp && tmp->type != pip && tmp->type != end)
	{
		if (tmp->type <= 3)
			get_and_delete(&tmp, lst_token, cmd, check);
		else
			tmp = tmp->next;
		check = 1;
	}
}

void			get_and_delete(t_token **tmp, t_token **lst_token, t_cmd *cmd, int check)
{
	t_token		*start;
	t_token		*end;
	t_type		redir_type;

	start = *tmp;
	redir_type = (*tmp)->type;
	*tmp = (*tmp)->next;
	if ((*tmp)->type == space)
		*tmp = (*tmp)->next;
	get_redir_fd((*tmp)->str, cmd, redir_type);
	if ((*tmp)->type == space)
		*tmp = (*tmp)->next;
	end = *tmp;
	*tmp = (*tmp)->next;
	if (check != 0)
		del_start_to_end(lst_token, start, end);
	else
		while (*lst_token != *tmp)
			*lst_token = (*lst_token)->next;
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
