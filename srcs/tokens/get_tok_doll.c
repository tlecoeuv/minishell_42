/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tok_doll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 12:57:34 by austin            #+#    #+#             */
/*   Updated: 2020/10/19 14:24:39 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			get_tok_doll(char *input, t_elem *elem,
								const t_type *elem_to_type, t_token **tokens)
{
	char	*str;

	if (elem->size == 1)
	{
		if (input[1] == '\"' || input[1] == '\'')
		{
			if (!(str = ft_strdup("")))
				return (ERROR);
		}
		else if (!(str = ft_strdup("$")))
			return (ERROR);
		elem->name = none;
	}
	else if (!(str = ft_substr(input, 1, elem->size - 1)))
		return (ERROR);
	if (!(append_token(tokens, str, elem_to_type[elem->name])))
		return (ERROR);
	return (SUCCESS);
}
