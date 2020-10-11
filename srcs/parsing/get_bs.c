/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_bs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 12:44:29 by austin            #+#    #+#             */
/*   Updated: 2020/10/11 17:06:16 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char				*get_str_bs(char *input, t_elem *elem, int quotes)
{
	char			*str;
	t_elem_name		escaped;

	escaped = get_elem_name(input + 1, elem);
	if (quotes)
	{
		if (escaped == d_quote || escaped == doll)
		{
			if (!(str = ft_substr(input + 1, 0, 1)))
				return (NULL);
		}
		else
			if (!(str = ft_substr(input, 0, 2)))
				return (NULL);
	}
	else if (escaped == none)
	{
		if (!(str = ft_substr(input + 1, 0, 1)))
			return (NULL);
	}
	else
		if (!(str = ft_substr(input + 1, 0, ft_strlen(elem->str[elem->name]))))
			return (NULL);
	return (str);
}

void		get_tok_bs(char *input, t_elem *elem, t_type *elem_to_type,
																t_token *tokens)
{
	char *str;

	if (!(str = get_str_bs(input, elem, 0)))
		return ;
	append_token(tokens, str, elem_to_type[elem->name]);
}
