/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 09:43:49 by tanguy            #+#    #+#             */
/*   Updated: 2020/11/17 10:38:05 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

	if (!lst_token)
		return (0);
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
		free(cmds[i]->bin_path);
		free(cmds[i]);
		i++;
	}
}
