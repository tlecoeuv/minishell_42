/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_lstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 12:45:16 by avieira           #+#    #+#             */
/*   Updated: 2020/10/02 14:07:20 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_token			*tok_lstnew(void *content)
{
	t_token		*new;

	if (!(new = malloc(sizeof(new))))
		return (NULL);
	new->str = content;
	new->next = NULL;
	return (new);
}
