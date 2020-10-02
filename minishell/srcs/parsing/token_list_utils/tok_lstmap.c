/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_lstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:25:33 by avieira           #+#    #+#             */
/*   Updated: 2020/10/02 14:06:56 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	*lstclear(t_token **lst, void (*del)(void *))
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
	return (NULL);
}

t_token		*tok_lstmap(t_token *lst, void *(*f)(void *), void (*del)(void *))
{
	t_token	*new_lst;
	t_token	*a;
	t_token	*b;

	new_lst = NULL;
	if (lst)
		if (!(new_lst = malloc(sizeof(t_token *))))
			return (NULL);
	a = new_lst;
	b = new_lst;
	while (lst)
	{
		a = b;
		a->str = (*f)(lst->str);
		if (lst->next)
		{
			if (!(b = malloc(sizeof(b))))
				return (lstclear(&new_lst, del));
			a->next = b;
		}
		else
			a->next = NULL;
		lst = lst->next;
	}
	return (new_lst);
}
