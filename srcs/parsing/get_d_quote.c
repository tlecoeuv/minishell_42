/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_d_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:10:57 by avieira           #+#    #+#             */
/*   Updated: 2020/10/15 13:32:49 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void			get_tok_d_quote(char *input, t_elem *elem, t_type *elem_to_type,
															t_token **tokens)
{
	int			len;
	t_elem		current;

	len = 1;
	current.str = elem->str;
	while (len < elem->size - 1)
	{
		current.name = get_elem_name(&input[len], &current);
		current.size = get_elem_size(&input[len], &current);
		printf("%s\n", ft_substr(&input[len], 0, current.size));
		if (current.name == bs )
			get_tok_bs(&input[len], elem, elem_to_type, tokens);
		else if (current.name == doll)
			get_tok_doll(&input[len], &current, elem_to_type, tokens);
		else
		{
			current.name = none;
			get_tok_word(&input[len], &current, elem_to_type, tokens);
		}
		len += current.size;
	}
}
