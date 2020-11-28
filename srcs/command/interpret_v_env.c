/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_v_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:35:20 by tanguy            #+#    #+#             */
/*   Updated: 2020/11/28 11:02:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		interpret_v_env(t_token *lst_token)
{
	replace_v_env(lst_token);
	retokenise_vars(&lst_token);
	tok_join_words(&lst_token);
}

void		first_v_env(t_token **lst_token, t_token **previous, int t)
{
	char	*env_value;

	env_value = ft_getenv((*lst_token)->str);
	if (env_value)
	{
		free((*lst_token)->str);
		if (t == 0)
			(*lst_token)->str = ft_strdup(env_value);
		else
			(*lst_token)->str = env_value;
		(*lst_token)->type = word;
		(*previous) = (*lst_token);
		(*lst_token) = (*lst_token)->next;
	}
	else
	{
		free((*lst_token)->str);
		(*lst_token)->type = space;
		(*lst_token)->str = ft_strdup(" ");
		(*previous) = (*lst_token);
		(*lst_token) = (*lst_token)->next;
	}
}

void		one_v_env(t_token **lst_token, t_token **previous, int t)
{
	t_token	*tmp;
	char	*env_value;

	env_value = ft_getenv((*lst_token)->str);
	if (env_value)
	{
		free((*lst_token)->str);
		if (t == 0)
			(*lst_token)->str = ft_strdup(env_value);
		else
			(*lst_token)->str = env_value;
		(*lst_token)->type = word;
		(*previous) = (*lst_token);
		(*lst_token) = (*lst_token)->next;
	}
	else
	{
		tmp = (*lst_token);
		(*lst_token) = (*lst_token)->next;
		(*previous)->next = (*lst_token);
		tok_lstdelone(tmp);
	}
}

void		replace_v_env(t_token *lst_token)
{
	t_token	*previous;

	previous = lst_token;
	if (lst_token && lst_token->type == v_env)
		first_v_env(&lst_token, &previous, lst_token->str[0] == '?');
	else if (lst_token)
		lst_token = lst_token->next;
	else
		return ;
	while (lst_token && lst_token->type != end)
	{
		if (lst_token->type == v_env)
			one_v_env(&lst_token, &previous, lst_token->str[0] == '?');
		else
		{
			previous = lst_token;
			lst_token = lst_token->next;
		}
	}
}
