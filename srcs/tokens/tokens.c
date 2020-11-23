/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 11:40:39 by austin            #+#    #+#             */
/*   Updated: 2020/10/20 18:01:27 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void				ini_get_tok(int (*get_tok[12])(char *, t_elem *,
								const t_type *elem_to_type, t_token **tokens))
{
	get_tok[cln] = &get_tok_sign;
	get_tok[inf] = &get_tok_sign;
	get_tok[d_sup] = &get_tok_sign;
	get_tok[sup] = &get_tok_sign;
	get_tok[d_quote] = &get_tok_d_quote;
	get_tok[quote] = &get_tok_quote;
	get_tok[spc] = &get_tok_sign;
	get_tok[tab] = &get_tok_sign;
	get_tok[bs] = &get_tok_bs;
	get_tok[sm_cl] = &get_tok_sign;
	get_tok[doll] = &get_tok_doll;
	get_tok[none] = &get_tok_word;
}

int					create_tokens_list(char *input, t_token **tokens)
{
	t_elem			elem;
	const char		*str_elem[] = {CLN, INF, D_SUP, SUP, D_QUOTE, QUOTE, SPC,
												TAB, BS, SM_CL, DOLL, NULL};
	const t_type	elem_to_type[] = {pip, in, append_out, out, word, word,
										space, space, word, end, v_env, word};
	int				(*get_tk[12])(char *, t_elem *, const t_type *, t_token **);

	*tokens = NULL;
	ini_get_tok(get_tk);
	elem.str = str_elem;
	while (*input)
	{
		elem.name = get_elem_name(input, &elem);
		elem.size = get_elem_size(input, &elem);
		if (!get_tk[elem.name](input, &elem, elem_to_type, tokens))
			return (ERROR);
		input += elem.size;
	}
	if (!tok_join_words(tokens))
		return (ERROR);
	return (SUCCESS);
}
