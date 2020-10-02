/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:37:32 by austin            #+#    #+#             */
/*   Updated: 2020/10/02 22:04:34 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			filter_escapes(t_token *tokens)
{
	t_token	*temp;

	temp = tokens->next;
	while (temp)
	{
		if (temp->type == bs)
		{
			tokens->next = temp->next;
			tok_lstdelone(temp, &free); // &free fonctionne vraiment ?
			if (tokens->next)
				if (tokens->next->type != cmd && tokens->next->type != cmd_arg)
					tokens->next->type = cmd_arg;
			temp = tokens->next;
		}
		else
		{
			tokens = temp;
			temp = tokens->next;
		}
	}
	return (1);
}

int			filter_tokens(t_token *tokens)
{
	filter_escapes(tokens);
	//filter_quotes();
	//merge_cmd_args();
	//merge_d_sup();
	return (1);
}
