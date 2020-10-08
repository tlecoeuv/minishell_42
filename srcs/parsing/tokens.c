/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 11:40:39 by austin            #+#    #+#             */
/*   Updated: 2020/10/09 00:26:38 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char		*get_token(char *input, t_token *tokens, const char **signs,
															t_token_type type)
{
	char	*str;
	t_token	*new;

	/*if (type == bs)
		new = get_bs_token();
	else if (type == quote || type == d_quote)
		new = get_quote_token();
	else if (type == v_env)
		new = get_v_env_token();*/
	//else
	{
		str = get_str_simple_token(input, type, signs);
		if ((type == word && !str))
			return (NULL);
		if (!(new = tok_lstnew(str)))
		{
			free(str);
			return (NULL);
		}
	}
	if (!new)
		return (NULL);
	new->type = type;
	tok_lstadd_back(&tokens, new);
	return (input + get_l_token(input, type, signs));
}

void			create_tokens_list(char *input, t_token *tokens)
{
	const char		*signs[] = {OPE, SM_CL, DOLL, BS, QUOTE, D_QUOTE, SPACE, 0};
	t_token_type	type;

	while (*input)
	{
		type = wich_type(input, signs);
		input = get_token(input, tokens, signs, type);
	}
}


int				main(void)
{
	t_token *tokens;
	t_token	*temp;
	char	*input;
	char	*types[12] = {"ope", "sm_cl", "v_env", "bs", "quote", "d_quote", "space", "word", "pip", "inf", "sup", "d_sup"};

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
		printf("\nDone\n");
	}
}
