/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 11:02:50 by tanguy            #+#    #+#             */
/*   Updated: 2020/11/02 17:59:30 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		printf_lst_token(t_token *lst_token)
{
	while (lst_token)
	{
		printf("type %d, str: |%s|\n", lst_token->type, lst_token->str);
		lst_token = lst_token->next;
	}
}

t_cmd		**get_commands(t_token **lst_token, int *nb_cmds)
{
	t_cmd	**cmds;
	int		i;

	i = 0;
	interpret_v_env(*lst_token);
	delete_cmd_spaces(*lst_token);
	*nb_cmds = get_nb_commands(*lst_token);
	if (!(cmds = malloc(sizeof(t_cmd *) * (*nb_cmds + 1))))
		return (NULL);
	while (i < *nb_cmds)
	{
		if (!(cmds[i] = malloc(sizeof(t_cmd))))
			return(NULL);
		get_redir(lst_token, cmds[i]);
		cmds[i]->args = create_cmd_args(lst_token);
		if (*lst_token && (*lst_token)->type == pip)
			*lst_token = (*lst_token)->next;
		i++;
	}
	cmds[i] = NULL;
	if (*lst_token && (*lst_token)->type == end)
		*lst_token = (*lst_token)->next;
	return (cmds);
}

char		**create_cmd_args(t_token **lst_token)
{
	char	**args;
	int		size_args;
	int		i;

	i = 0;
	size_args = get_size_args(*lst_token);
	if (!(args = malloc(sizeof(char *) * (size_args + 1))))
		return (NULL);
	while (i < size_args)
	{
		if ((*lst_token)->type == word)
		{
			args[i] = ft_strdup((*lst_token)->str);
			i++;
		}
		*lst_token = (*lst_token)->next;
	}
	if((*lst_token) && (*lst_token)->type == space)
		*lst_token = (*lst_token)->next;
	args[i] = NULL;
	return (args);
}
