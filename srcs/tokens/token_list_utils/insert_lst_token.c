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

t_token		*insert_lst_token(t_token *pre_token, t_token *new_tokens)
{
	t_token	*last_in_new;

	last_in_new = tok_lstlast(new_tokens);
	last_in_new->next = pre_token->next;
	pre_token->next = new_tokens;
	return (last_in_new);
}
