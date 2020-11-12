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

void		replace(t_token **tokens, t_token *before, t_token *after)
{
	t_token	*old_left;
	t_token	*new_right;

	old_left = *tokens;
	new_right = tok_lstlast(after);
	if (*tokens == before)
		*tokens = after;
	else
	{
		while (old_left->next != before)
			old_left = old_left->next;
		old_left->next = after;
	}
	new_right->next = before->next;
	tok_lstdelone(before);
}
