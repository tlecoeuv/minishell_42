/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elem_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <austin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 23:04:44 by austin            #+#    #+#             */
/*   Updated: 2020/10/21 23:50:05 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_elem_name				get_elem_name(char *input, t_elem *elem)
{
	t_elem_name			name;

	name = -1;
	while (elem->str[++name])
		if (!ft_strncmp(elem->str[name], input, ft_strlen(elem->str[name])))
			return (name);
	return (name);
}

int						get_len_input_doll(char *input, t_elem *elem)
{
	int					len;
	int					len_valid;

	(void)elem;
	len = 1;
	len_valid = get_len_valid_identifier(&input[len]);
	if (len_valid == -1)
		return (len);
	return (len + len_valid);
}

int						get_len_input_quotes(char *input, t_elem *elem)
{
	int					l;
	int					n_quotes;
	t_elem_name			quotes;

	n_quotes = 0;
	l = 0;
	while (n_quotes != 2 && input[l])
	{
		quotes = get_elem_name(&input[l], elem);
		if (quotes == elem->name)
			n_quotes++;
		else if (quotes == bs && elem->name == d_quote)
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
	int					len;

	name = elem->name;
	if (name == pip || name == inf || name == sup || name == sm_cl)
		return (1);
	len = 0;
	while (name == spc || name == tab)
		name = get_elem_name(&input[len++], elem);
	if (len)
		return (len - 1);
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
