/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 12:33:27 by austin            #+#    #+#             */
/*   Updated: 2020/10/13 12:53:14 by avieira          ###   ########.fr       */
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
	tok_lstadd_back(tokens, new);
}
