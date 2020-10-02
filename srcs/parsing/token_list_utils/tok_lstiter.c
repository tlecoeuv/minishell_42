/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_lstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:23:33 by avieira           #+#    #+#             */
/*   Updated: 2020/10/01 16:24:15 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	tok_lstiter(t_token *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->str);
		lst = lst->next;
	}
}