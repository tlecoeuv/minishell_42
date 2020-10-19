/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_lstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:42:27 by avieira           #+#    #+#             */
/*   Updated: 2020/10/19 14:59:33 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	tok_lstclear(t_token **lst)
{
	t_token	*temp;

	if (!(temp = *lst))
		return ;
	if (temp->str)
		free(temp->str);
	*lst = (*lst)->next;
	free(temp);
	while (*lst)
	{
		temp = *lst;
		if (temp->str)
			free(temp->str);
		*lst = (*lst)->next;
		free(temp);
	}
	*lst = NULL;
}
