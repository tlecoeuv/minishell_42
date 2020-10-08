/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 23:04:44 by austin            #+#    #+#             */
/*   Updated: 2020/10/08 19:01:09 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token_type	wich_type(char *input, const char **signs)
{
	t_token_type	type;

	type = is_in_strings(*input, signs);
	if (type == ope)
	{
		if (*input == '|')
			return (pip);
		if (*input == '<')
			return (inf);
		if (*input == '>')
		{
			if (*(input + 1) == '>')
				return (d_sup);
			else
				return (sup);
		}
	}
	return (type);
}

int			is_in_strings(char c, const char *signs[])
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (signs[++i])
	{
		while (signs[i][++j])
			if (signs[i][j] == c)
				return (i);
		j= -1;
	}
	return (i);
}
