/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_start_to_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:01:39 by austin            #+#    #+#             */
/*   Updated: 2020/10/20 01:58:08 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void		del_start_to_end(t_token **tokens, t_token *start, t_token *end)
{
	t_token	*temp;
	t_token	*stop;

	temp = *tokens;
	if (start == *tokens)
		*tokens = end->next;
	else
	{
		while (temp->next != start)
			temp = temp->next;
		temp->next = end->next;
	}
	stop = end->next;
	while (start != stop)
	{
		temp = start;
		start = start->next;
		tok_lstdelone(temp);
	}
}
