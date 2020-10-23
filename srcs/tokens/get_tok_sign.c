/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tok_str_null.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 12:57:34 by austin            #+#    #+#             */
/*   Updated: 2020/10/20 03:39:00 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			get_tok_sign(char *input, t_elem *elem,
								const t_type *elem_to_type, t_token **tokens)
{
	char	*str;

	(void)input;
	if (!(str = ft_strdup((char *)elem->str[elem->name])))
		return (ERROR);
	if (!(append_token(tokens, str, elem_to_type[elem->name])))
		return (ERROR);
	return (SUCCESS);
}
