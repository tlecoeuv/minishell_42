/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_lstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:42:27 by avieira           #+#    #+#             */
/*   Updated: 2020/10/02 14:06:23 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	tok_lstclear(t_token **lst, void (*del)(void *))
{
	t_token	*temp;

	temp = (*lst);
	(*del)((*lst)->str);
	*lst = (*lst)->next;
	temp = NULL;
	while (*lst)
	{
		temp = (*lst);
		(*del)((*lst)->str);
		*lst = (*lst)->next;
		free(temp);
	}
}
