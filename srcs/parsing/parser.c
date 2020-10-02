/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 11:40:39 by austin            #+#    #+#             */
/*   Updated: 2020/10/02 15:38:43 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"



int				get_sign_token(const char *sign, t_token *tokens, int *len)
{
	char		*str_temp;
	t_token		*new;

	if (!(str_temp = ft_strdup(sign)))
		return (0);
	if (!(new = tok_lstnew(str_temp)))
		return (0);
	tok_lstadd_back(&tokens, new);
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
	*len += l;
	if (!(str_temp = ft_substr(input, 0, l)))
		return (0);
	if (!(new = tok_lstnew(str_temp)))
		return (0);
	tok_lstadd_back(&tokens, new);
	return (1);
}

int				get_current_token(int *len, char *input, const char *signs[],
																t_token *tokens)
{
	int			i;

	while (*input == ' ' || *input == '\t')
	{
		input++;
		(*len)++;
	}
	i = -1;
	while (signs[++i])					//SIGN
		if (!ft_strcmp(signs[i], input))
		{
			if (!get_sign_token(signs[i], tokens, len))
				return (0);
			return (1);
		}
	if (ft_isalnum(*input))
		if (!get_word_token(len, input, tokens))
			return (0);
	return (1);
}

void			parser(char *input, t_token *tokens)
{
	int			len_to_next;
	const char	*signs[10] = {PIPE, INF, D_SUP, SUP, SM_CL, DOLL, BS, QUOTE,
	D_QUOTE, NULL};

	while (*input)
	{
		len_to_next = 0;
		get_current_token(&len_to_next, input, signs, tokens);
		input += len_to_next;
	}
}

/*int				main(int ac, char **av)
{
	t_token		*tokens;

	tokens = tok_lstnew("Pointer on list");
	(void)ac;
	parser(av[1], tokens);
	while (tokens)
	{
		printf("%s\n", tokens->str);
		tokens = tokens->next;
	}
}*/
