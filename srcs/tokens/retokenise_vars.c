/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 11:40:39 by austin            #+#    #+#             */
/*   Updated: 2020/10/20 18:01:27 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token					*create_vars_tokens(t_token *pre_new,
														t_token **new_tokens)
{
	char				*str;
	char				*str_space;
	int					i;

	str = pre_new->str;
	while (*str)
	{
		if (*str == ' ')
		{
			if (!(str_space = ft_strdup(" ")))
				return (NULL);
			append_token(new_tokens, str_space, space);
			while (*str == ' ')
				str++;
		}
		else
		{
			i = 0;
			while (str[i] != ' ' && str[i])
				i++;
			append_token(new_tokens, ft_substr(str, 0, i), word);
			str += i;
		}
	}
	if (*new_tokens)
	{
		free(pre_new->str);
		pre_new->str = (*new_tokens)->str;
		pre_new->type = (*new_tokens)->type;
		if ((*new_tokens)->next)
			return (insert_lst_token(pre_new, (*new_tokens)->next));
	}
	return (pre_new);
}

void					retokenise_vars(t_token **tokens)
{
	t_token			*new_tokens;
	t_token			*temp;

	temp = *tokens;
	while (temp)
	{
		new_tokens = NULL;
		if (temp->type == word && temp->retokenise)
		{
			temp = create_vars_tokens(temp, &new_tokens);
		}
		temp = temp->next;
	}
}
