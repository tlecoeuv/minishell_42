/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 11:40:39 by austin            #+#    #+#             */
/*   Updated: 2020/10/11 17:07:06 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void			ini_get_tok(f_get_tok *get_tok)
{
	get_tok[cln] = &get_tok_str_null;
	get_tok[inf] = &get_tok_str_null;
	get_tok[d_sup] = &get_tok_str_null;
	get_tok[sup] = &get_tok_str_null;
	get_tok[d_quote] = &get_tok_d_quote;
	get_tok[quote] = &get_tok_quote;
	get_tok[spc] = &get_tok_str_null;
	get_tok[tab] = &get_tok_str_null;
	get_tok[bs] = &get_tok_bs;
	get_tok[sm_cl] = &get_tok_str_null;
	get_tok[doll] = &get_tok_doll;
	get_tok[none] = &get_tok_word;

}

int				create_tokens_list(char *input, t_token *tokens)
{
	t_elem		elem;
	const char	*str_elem[] = {CLN, INF, D_SUP, SUP, D_QUOTE, QUOTE, SPC,
									TAB, BS, SM_CL, DOLL, ""};
	t_type		elem_to_type[] = {pip, in, append_out, out, word,
									word, space, space, word, end, v_env, word};
	f_get_tok	get_tok[12];

	ini_get_tok(get_tok);
	elem.str = str_elem;
	while (*input)
	{
		elem.name = get_elem_name(input, &elem);
		elem.size = get_elem_size(input, &elem);
		get_tok[elem.name](input, &elem, elem_to_type, tokens);
		input += elem.size;
	}
	return (SUCCESS);
}


int				main(void)
{
	t_token *tokens;
	t_token	*temp;
	char	*input;
	char	*types[12] = {"pip", "in", "out", "append_out", "word", "space", "v_env", "end"};

	while (get_next_line(0, &input) == 1)
	{
		tokens = tok_lstnew("Pointer on list");
		tokens->type = word;
		create_tokens_list(input, tokens);
		temp = tokens;
		if (temp->next)
			temp = temp->next;
		while (temp)
		{
			printf("str : \"%s\"      type : %s\n", temp->str, types[temp->type]);
			temp = temp->next;
		}
		printf("Done\n\n");
	}
}
