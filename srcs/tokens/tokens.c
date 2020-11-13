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

void				display_tokens(t_token **tokens)
{
	t_token			*temp;
	const char		*types[12] = {"pip", "in", "out", "append_out", "word",
													"space", "v_env", "end"};

	temp = *tokens;
	while (temp)
	{
		printf("str : \"%s\"    type : %s   re :%d\n", temp->str, types[temp->type], (int)temp->retokenise);
		temp = temp->next;
	}
	printf("\nDone\n\n");
}

t_token					*create_vars_tokens(char **split, t_token *pre_new,
														t_token **new_tokens)
{
	int					i;

	i = 0;
	free(pre_new->str);
	pre_new->str = split[i];
	pre_new->retokenise = 0;
	while (split[++i])
		append_token(new_tokens, split[i], word);
	return (insert_lst_token(pre_new, *new_tokens));
}

void					retokenise_vars(t_token **tokens)
{
	t_token			*new_tokens;
	t_token			*temp;
	char			**split;

	temp = *tokens;
	new_tokens = NULL;
	while (temp)
	{
		if (temp->type == word && temp->retokenise)
		{
			if (!(split = ft_split(temp->str, ' ')))
				return ;
			if (get_array_size(split) > 1)
			{
				temp = create_vars_tokens(split, temp, &new_tokens);
				free(split);
			}
			else
				free_array(split);
		}
		temp = temp->next;
	}
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
	//retokenise_vars(tokens);
	//display_tokens(tokens);
	return (SUCCESS);
}
