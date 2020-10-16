/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tok_doll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 12:57:34 by austin            #+#    #+#             */
/*   Updated: 2020/10/16 02:25:34 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		get_tok_doll(char *input, t_elem *elem,
								const t_type *elem_to_type, t_token **tokens)
{
	char	*str;

	if (!(str = ft_substr(input, 1, elem->size - 1)))
		return ;
	append_token(tokens, str, elem_to_type[elem->name]);
}
