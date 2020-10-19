/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_join_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:37:48 by austin            #+#    #+#             */
/*   Updated: 2020/10/19 16:42:15 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token			*get_end_word(t_token *start)
{
	t_token		*end;

	end = start;
	while (end->next)
	{
		if (end->next->type != word)
			return (end);
		end = end->next;
	}
	return (end);
}

char			*tok_join_str(t_token *start, t_token *end)
{
	char		*str;
	char		*temp;

	if (!(str = ft_strdup("")))
		return (NULL);
	while (start != end->next)
	{
		temp = str;
		if (!(str = ft_strjoin(str, start->str)))
			return (NULL);
		free(temp);
		start = start->next;
	}
	return (str);
}

int				tok_join_words(t_token **tokens)
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
				return (ERROR);
			del_start_to_end(tokens, start->next, end);
			free(start->str);
			start->str = str;
		}
		start = start->next;
	}
	return (SUCCESS);
}
