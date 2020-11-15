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

t_token					*create_vars_tokens(t_token *pre_new,
														t_token **new_tokens)
{
	char				*str;
	char				*str_space;
	int					i;

	str = pre_new->str;
	while (*str)
	{
		if (*str == ' ')
		{
			if (!(str_space = ft_strdup(" ")))
				return (NULL);
			append_token(new_tokens, str_space, space);
			while (*str == ' ')
				str++;
		}
		else
		{
			i = 0;
			while (str[i] != ' ' && str[i])
				i++;
			append_token(new_tokens, ft_substr(str, 0, i), word);
			str += i;
		}
	}
	if (*new_tokens)
	{
		free(pre_new->str);
		pre_new->str = (*new_tokens)->str;
		pre_new->type = (*new_tokens)->type;
		if ((*new_tokens)->next)
			return (insert_lst_token(pre_new, (*new_tokens)->next));
	}
	return (pre_new);
}

void					retokenise_vars(t_token **tokens)
{
	(void)tokens;
	t_token			*new_tokens;
	t_token			*temp;

	temp = *tokens;
	while (temp)
	{
		new_tokens = NULL;
		if (temp->type == word && temp->retokenise)
		{
			temp = create_vars_tokens(temp, &new_tokens);
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
	//display_tokens(tokens);
	return (SUCCESS);
}
