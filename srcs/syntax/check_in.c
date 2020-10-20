/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 02:10:06 by austin            #+#    #+#             */
/*   Updated: 2020/10/20 17:22:11 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			check_in(t_token *tokens, t_token *go)
{
	t_token	*next;

	next = get_next_skip_space(go);
	(void)tokens;
	if (!next)
		return (syntax_error("newline"));
	if (next->type != word)
		return (syntax_error(next->str));
	return (SUCCESS);
}
