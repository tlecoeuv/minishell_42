/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:25:26 by austin            #+#    #+#             */
/*   Updated: 2020/10/08 20:14:36 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		get_l_quote(char *input, t_token_type type, const char **signs)
{
	int	l;
	int n_quote;
	t_token_type	temp_type;

	l = 0;
	temp_type = type;
	while (temp_type < pip && temp_type != sm_cl && !(n_quote % 2) &&
																	input[l])
	{
		n_quote = (temp_type == type) ? n_quote + 1 : n_quote;
		l++;
		temp_type = wich_type(&input[l], signs);
	}
	while (wich_type(&input[l], signs) != type)
		l--;
	return (l);
}

int		get_l_env_word(char *input, t_token_type type, const char **signs)
{
	int	l;
	t_token_type temp_type;

	l = 0;
	temp_type = type;
	while (temp_type != space && temp_type != sm_cl && input[l] &&
														temp_type < pip)
	{
		
		l++;
		temp_type = wich_type(&input[l], signs);
	}
	return (l);
}

int		get_l_token(char *input, t_token_type type, const char **signs)
{
	int	l;

	l = 0;
	l = (type == inf || type == sup || type == pip || type == sm_cl) ? 1 : l;
	l = (type == d_sup || type == bs) ? 2 : l;
	if (type == quote || type == d_quote)
		l = get_l_quote(input, type, signs);
	if (type == v_env || type == word)
		l = get_l_env_word(input, type, signs);
	if (type == space)
		while (wich_type(&input[l], signs) == space && input[l])
			l++;
	return (l);
}

char	*get_str_simple_token(char *input, t_token_type type, const char **signs)
{
	char	*str;
	int		l;

	if (type == inf || type == sup || type == pip || type == d_sup ||
	type == sm_cl || type == space)
		str = NULL;
	l = 0;
	if (type == word)
		while (wich_type(&input[l], signs) == word && input[l])
			l++;
	if (l)
		str = ft_substr(input, 0, l);
	return (str);
}
