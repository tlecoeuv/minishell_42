/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tok_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 12:57:34 by austin            #+#    #+#             */
/*   Updated: 2020/10/15 13:33:24 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		get_tok_quote(char *input, t_elem *elem, t_type *elem_to_type,
															t_token **tokens)
{
	char	*str;

	if (!(str = ft_substr(input + 1, 0, elem->size - 1)))
		return ;
	append_token(tokens, str, elem_to_type[elem->name]);
}
