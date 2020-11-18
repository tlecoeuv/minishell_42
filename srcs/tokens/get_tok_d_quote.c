/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tok_d_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:10:57 by avieira           #+#    #+#             */
/*   Updated: 2020/10/19 14:50:45 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int				doll_in_d_quote(char *input, t_elem *current,
								const t_type *elem_to_type, t_token **tokens)
{
	int		ret;
	t_token	*last;

	ret = get_tok_doll(input, current, elem_to_type, tokens);
	last = tok_lstlast(*tokens);
	last->retokenise = 0;
	return (ret);
}

int				d_quote_manage(char *input, t_elem *elem,
								const t_type *elem_to_type, t_token **tokens)
{
	int			len;
	int			ret;
	t_elem		current;

	len = 1;
	current.str = elem->str;
	ret = SUCCESS;
	while (len < (elem->size - (input[elem->size - 1] == '"')) && ret)
	{
		current.name = get_elem_name(&input[len], &current);
		current.size = get_elem_size(&input[len], &current);
		if (current.name == bs)
			ret = get_tok_bs(&input[len], elem, elem_to_type, tokens);
		else if (current.name == doll)
			ret = doll_in_d_quote(&input[len], &current, elem_to_type, tokens);
		else
		{
			if (current.size >= (elem->size - len))
				current.size = elem->size - len - 1;
			current.name = none;
			ret = get_tok_word(&input[len], &current, elem_to_type, tokens);
		}
		len += current.size;
	}
	return (ret);
}

int				get_tok_d_quote(char *input, t_elem *elem,
								const t_type *elem_to_type, t_token **tokens)
{
	char		*str;

	if (elem->size < 3)
	{
		if (!(str = ft_strdup("")))
			return (ERROR);
		if (!(append_token(tokens, str, word)))
		{
			free(str);
			return (ERROR);
		}
	}
	else
	{
		if (d_quote_manage(input, elem, elem_to_type, tokens) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}
