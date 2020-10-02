/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 11:40:39 by austin            #+#    #+#             */
/*   Updated: 2020/10/02 22:02:51 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int				get_sign_token(const char *sign, t_token *tokens, int *len,
																	int i)
{
	char		*str_temp;
	t_token		*new;

	if (!(str_temp = ft_strdup((char *)sign)))
		return (0);
	if (!(new = tok_lstnew(str_temp)))
		return (0);
	tok_lstadd_back(&tokens, new);
	new->type = 3 + i;
	*len += ft_strlen(str_temp);
	return (1);
}

int				get_word_token(int *len, char *input, t_token *tokens)
{
	int			l;
	char		*str_temp;
	t_token		*new;

	l = 0;
	while (ft_isalnum(input[l]))
		l++;
	if (!l)
		while (input[l] == ' ' || input[l] == '\t')
			l++;
	if (!(str_temp = ft_substr(input, 0, l)))
		return (0);
	if (!(new = tok_lstnew(str_temp)))
		return (0);
	tok_lstadd_back(&tokens, new);
	*len += ft_strlen(str_temp);
	return (1);
}

int				get_current_token(int *len, char *input, const char *signs[],
																t_token *tokens)
{
	int			i;

	i = -1;
	if (ft_isalnum(*input) || *input == ' ' || *input == '\t')
	{
		if (!get_word_token(len, input, tokens))
			return (0);
	}
	else
	{
		while (signs[++i] && !*len)
			if (!ft_strcmp(signs[i], input))
				if (!get_sign_token(signs[i], tokens, len, i))
					return (0);
	}
	return (1);
}

void			parser(char *input, t_token *tokens)
{
	int			len_to_next;
	const char	*signs[9] = {PIPE, INF, SUP, SM_CL, DOLL, BS, QUOTE,
	D_QUOTE, NULL};

	while (*input)
	{
		len_to_next = 0;
		get_current_token(&len_to_next, input, signs, tokens);
		input += len_to_next;
	}
	filter_tokens(tokens);
}

int				main(void)
{
	t_token		*tokens;
	t_token		*temp;
	char		*input;


	printf("Format : =token1==token2==...\n");
	while (get_next_line(0, &input) == 1)
	{
		tokens = tok_lstnew(ft_strdup("Pointer on list"));
		parser(input, tokens);
		temp = tokens;
		if (temp->next)
			temp = temp->next;
		while (temp)
		{
			printf("=%s[type->%d]=", temp->str, temp->type);
			temp = temp->next;
		}
		printf("\n");
		tok_lstclear(&tokens, &free);
	}
}
