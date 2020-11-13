/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 09:43:49 by tanguy            #+#    #+#             */
/*   Updated: 2020/11/13 11:35:50 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		interpret_v_env(t_token *lst_token)
{
	char	*env_value;
	t_token	*tmp;

	tmp = lst_token;
	while (tmp && tmp->type != end)
	{
		if (tmp->type == v_env)
		{
			env_value = ft_getenv(tmp->str);
			free(tmp->str);
			if (env_value)
				tmp->str = ft_strdup(env_value);
			else
				tmp->str = ft_strdup("");
			tmp->type = word;
		}
		tmp = tmp->next;
	}
	retokenise_vars(&lst_token);
	tok_join_words(&lst_token);
}

void		delete_cmd_spaces(t_token *lst_token)
{
	t_token		*previous;
	t_token		*tmp;

	previous = lst_token;
	if (lst_token)
		lst_token = lst_token->next;
	else
		return ;
	while (lst_token && lst_token->type != end)
	{
		if (lst_token->type == space)
		{
			tmp = lst_token;
			lst_token = lst_token->next;
			previous->next = lst_token;
			tok_lstdelone(tmp);
		}
		else
		{
			previous = lst_token;
			lst_token = lst_token->next;
		}
	}
}

int			get_size_args(t_token *lst_token)
{
	int		size;

	size = 0;
	while (lst_token && lst_token->type != end && lst_token->type > 3)
	{
		if (lst_token->type == word)
			size++;
		lst_token = lst_token->next;
	}
	return (size);
}

int			get_nb_commands(t_token *lst_token)
{
	int		size;

	size = 1;
	while (lst_token && lst_token->type != end)
	{
		if (lst_token->type == pip)
			size++;
		lst_token = lst_token->next;
	}
	return (size);
}

void		free_commands(t_cmd **cmds)
{
	int		i;

	i = 0;
	while (cmds[i])
	{
		free_array(cmds[i]->args);
	}
	free(cmds);
}
