/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 02:10:06 by austin            #+#    #+#             */
/*   Updated: 2020/10/20 18:04:22 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			check_pip(t_token *tokens, t_token *go)
{
	t_token	*previous;
	t_token *next;

	previous = get_previous_skip_space(tokens, go);
	next = get_next_skip_space(go);
	if (next)
		if ((previous->type == v_env || previous->type == word) &&
					(next->type == v_env || next->type == word))
			return (SUCCESS);
	return (syntax_error("|"));
}
