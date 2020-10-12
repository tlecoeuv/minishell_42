/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 12:33:27 by austin            #+#    #+#             */
/*   Updated: 2020/10/12 19:08:20 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void				append_token(t_token **tokens, char *str, t_type type)
{
	t_token		*new;

	if (!(new = tok_lstnew(str)))
	{
		if (str)
			free(str);
		return ;
	}
	new->type = type;
	if (*tokens)
		tok_lstadd_back(tokens, new);
	else
		*tokens = new;
}
