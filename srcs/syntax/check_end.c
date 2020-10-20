/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 02:10:06 by austin            #+#    #+#             */
/*   Updated: 2020/10/20 18:04:09 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			check_end(t_token *tokens, t_token *go)
{
	t_token	*previous;

	previous = get_previous_skip_space(tokens, go);

	if (previous->type == pip || previous->type == end || previous->type == in
		|| previous->type == out || previous->type == append_out)
		return (syntax_error(go->str));
	return (SUCCESS);
}
