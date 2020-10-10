/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 12:57:34 by austin            #+#    #+#             */
/*   Updated: 2020/10/10 13:15:27 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		get_tok_str_null(char *input, t_elem *elem, t_type *elem_to_type,
																t_token *tokens)
{
	(void)input;
	append_token(tokens, NULL, elem_to_type[elem->name]);
}

void		get_tok_d_quote(char *input, t_elem *elem, t_type *elem_to_type,
																t_token *tokens)
{
	//TEMPORAIRE
	append_token(tokens, ft_substr(input, 0, elem->size), elem_to_type[elem->name]);
}

void		get_tok_quote(char *input, t_elem *elem, t_type *elem_to_type,
																t_token *tokens)
{
	//TEMPORAIRE
	append_token(tokens, ft_substr(input, 0, elem->size), elem_to_type[elem->name]);
}

void		get_tok_word(char *input, t_elem *elem, t_type *elem_to_type,
																t_token *tokens)
{
	//TEMPORAIRE
	append_token(tokens, ft_substr(input, 0, elem->size), elem_to_type[elem->name]);
}

void		get_tok_doll(char *input, t_elem *elem, t_type *elem_to_type,
																t_token *tokens)
{
	//TEMPORAIRE
	append_token(tokens, ft_substr(input, 0, elem->size), elem_to_type[elem->name]);
}
