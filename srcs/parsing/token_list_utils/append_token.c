/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 12:33:27 by austin            #+#    #+#             */
/*   Updated: 2020/10/19 14:21:00 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int				append_token(t_token **tokens, char *str, t_type type)
{
	t_token		*new;

	if (!(new = tok_lstnew(str)))
	{
		if (str)
			free(str);
		return (ERROR);
	}
	new->type = type;
	tok_lstadd_back(tokens, new);
	return (SUCCESS);
}
