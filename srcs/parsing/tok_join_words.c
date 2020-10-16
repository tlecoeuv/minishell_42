/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_join_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:37:48 by austin            #+#    #+#             */
/*   Updated: 2020/10/16 02:05:58 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token			*get_end_word(t_token *start)
{
	while (start->next)
	{
		if (start->next->type != word)
			return (start);
		start = start->next;
	}
	return (start);
}

char			*tok_join_str(t_token *start, t_token *end)
{
	char		*str;

	if (!(str = ft_strdup("")))
		return (NULL);
	while (start != end->next)
	{
		if (!(str = ft_strjoin(str, start->str)))
			return (NULL);
		start = start->next;
	}
	return (str);
}

void			tok_join_words(t_token **tokens)
{
	t_token		*start;
	t_token		*end;
	char		*str;

	start = *tokens;
	while (start)
	{
		if (start->type == word)
		{
			end = get_end_word(start);
			if (!(str = tok_join_str(start, end)))
				return ;
			del_start_to_end(tokens, start->next, end);
			free(start->str);
			start->str = str;
		}
		start = start->next;
	}
}
