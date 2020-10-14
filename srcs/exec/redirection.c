/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 23:31:02 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/10/14 19:16:45 by tlecoeuv         ###   ########.fr       */
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
		cmd->redir_fd = get_redir_fd(lst_token, cmd->redir_type);
	}
}

int				get_redir_fd(t_token **lst_token, t_type redir_type)
{
	return (0);
}
