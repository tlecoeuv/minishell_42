/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:22:16 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/11/13 11:42:30 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	skip_redir(t_token **lst_token)
{
	while (*lst_token && (*lst_token)->type <= 3 && (*lst_token)->type != pip)
	{
		*lst_token = (*lst_token)->next;
		if ((*lst_token)->type == space)
			*lst_token = (*lst_token)->next;
		*lst_token = (*lst_token)->next;
		if ((*lst_token) && (*lst_token)->type == space)
			*lst_token = (*lst_token)->next;
	}
}
