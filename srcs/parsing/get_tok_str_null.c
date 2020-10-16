/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tok_str_null.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 12:57:34 by austin            #+#    #+#             */
/*   Updated: 2020/10/16 02:24:39 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		get_tok_str_null(char *input, t_elem *elem,
								const t_type *elem_to_type, t_token **tokens)
{
	(void)input;
	append_token(tokens, NULL, elem_to_type[elem->name]);
}
