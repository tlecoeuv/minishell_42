/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:18:26 by tanguy            #+#    #+#             */
/*   Updated: 2020/10/09 19:00:08 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		handle_tokens(t_token *lst_token)
{
	char	**cmd;
	printf("handle command start!\n");
	while(lst_token)
	{
		cmd = get_cmd_fro_tok(&lst_token);
	}
	exec_cmd(cmd);
	free_array(cmd);
}

char		**get_cmd_fro_tok(t_token **lst_token)
{
	int		size;
	char	**cmd;

	printf("get_cmd_fro_tok\n");
	size = get_size_cmd(*lst_token);
	cmd = create_cmd_tab(lst_token, size);
	return (cmd);
}

int			get_size_cmd(t_token *lst_token)
{
	int		size;

	size = 0;
	printf("get_size_cmd\n");
	while (lst_token && lst_token->type != sm_cl)
	{
		if (lst_token->type == word)
			size++;
		lst_token = lst_token->next;
	}
	return(size);
}

char		**create_cmd_tab(t_token **lst_token, int size)
{
		char	**cmd;
		int		i;

		i = 0;
		if (!(cmd = malloc(sizeof(char *) * (size + 1))))
			return (NULL);
		while (i < size)
		{
			if ((*lst_token)->type == word)
			{
				cmd[i] = ft_strdup((*lst_token)->str);
				i++;
			}
			*lst_token = (*lst_token)->next;
		}
		while(*lst_token && (*lst_token)->type != sm_cl)
			*lst_token = (*lst_token)->next;
		if((*lst_token)->type == sm_cl)
			*lst_token = (*lst_token)->next;
		return(cmd);
}

void		exec_cmd(char **cmd)
{
	int		i;

	i = 0;
	while(cmd[i])
	{
		printf("%s \n", cmd[i]);
	}
}

//while(wait(NULL) != -1 && errno != ECHILD);
