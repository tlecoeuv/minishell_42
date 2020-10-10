/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elem_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 23:04:44 by austin            #+#    #+#             */
/*   Updated: 2020/10/10 13:15:04 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_elem_name				get_elem_name(char *input, t_elem *elem)
{
	t_elem_name			name;

	name = -1;
	while (elem->str[++name])
		if (!ft_strcmp(elem->str[name], input))
			return (name);
	return (name);
}

int						get_len_input_doll(char *input, t_elem *elem)
{
	int					len;
	int					braces;
	(void)elem;

	braces = 0;
	len = 1;
	if (input[len] == BRACE_IN)
	{
		braces = 1;
		len += 2;
	}
	len += get_len_valid_identifier(&input[len], braces);
	return(len);
}

int						get_len_input_quotes(char *input, t_elem *elem)
{
	int					l;
	int					n_quotes;
	t_elem_name			quotes;

	n_quotes = 0;
	l = 0;
	while (!n_quotes && !(n_quotes % 2) && input[l])
	{
		quotes = get_elem_name(input, elem);
		if (quotes == quote || quotes == d_quote)
			n_quotes++;
		else if (quotes == bs)
			l++;
		if (input[l])
			l++;
	}
	return (l);
}

int						get_len_input_word(char *input, t_elem *elem)
{
	int					len;

	len = 0;
	while (input[len] && get_elem_name(&input[len], elem) == none)
		len++;
	return (len);
}

int						get_elem_size(char *input, t_elem *elem)
{
	t_elem_name			name;

	name = elem->name;
	if (name == pip || name == inf || name == sup || name == d_quote ||
		name == quote || name == spc || name == tab || name == sm_cl)
		return (1);
	if (name == d_sup)
		return (2);
	if (name == bs)
	{
		if (*(input + 1))
			return (2);
		return (1);
	}
	if (name == doll)
		return (get_len_input_doll(input, elem));
	if (name == d_quote || name == quote)
		return (get_len_input_quotes(input, elem));
	return (get_len_input_word(input, elem));
}
