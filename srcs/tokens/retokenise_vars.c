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

char					*create_vars_tokens(char *str, t_token **new_tokens)
{
	char				*str_space;
	int					i;

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
	return (str);
}

void					retokenise_vars(t_token **tokens)
{
	t_token			*new_tokens;
	t_token			*temp;
	char			*str;

	temp = *tokens;
	while (temp)
	{
		new_tokens = NULL;
		if (temp->type == word && temp->retokenise)
		{
			str = temp->str;
			while (*str)
				str = create_vars_tokens(str, &new_tokens);
			if (new_tokens)
			{
				free(temp->str);
				temp->str = new_tokens->str;
				temp->type = new_tokens->type;
				if (new_tokens->next)
					temp = insert_lst_token(temp, new_tokens->next);
				free(new_tokens);
			}
		}
		temp = temp->next;
	}
}
