/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tok_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 12:57:34 by austin            #+#    #+#             */
/*   Updated: 2020/10/19 15:53:03 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			get_tok_word(char *input, t_elem *elem,
								const t_type *elem_to_type, t_token **tokens)
{
	char	*str;

	if (!(str = ft_substr(input, 0, elem->size)))
		return (ERROR);
	if (!(append_token(tokens, str, elem_to_type[elem->name])))
		return (ERROR);
	return (SUCCESS);
}
