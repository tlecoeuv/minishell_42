/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:18:26 by tanguy            #+#    #+#             */
/*   Updated: 2020/10/21 23:09:46 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		handle_tokens(t_token *lst_token)
{
	t_cmd	*cmd;

	while (lst_token)
	{
		printf("what: %s\n",lst_token->str);
		cmd = get_cmd_from_tok(&lst_token);
		if (is_builtin(cmd->args[0]))
			exec_builtin(cmd);
		else
		{
			if (!get_absolute_path(cmd->args))
				error_cmd_not_found(cmd->args[0]);
			else
				exec_cmd(cmd);
		}
		free_array(cmd->args);
		free(cmd);
	}
}

t_cmd		*get_cmd_from_tok(t_token **lst_token)
{
	int		size;
	t_cmd	*cmd;

	if (!(cmd = malloc(sizeof(t_cmd))))
		return(NULL);
	size = get_size_cmd(*lst_token);
	cmd->args = create_cmd_args(lst_token, size);
	get_redir_and_fd(lst_token, cmd);
	if ((*lst_token) && (*lst_token)->type == end)
		*lst_token = (*lst_token)->next;
	return (cmd);
}

int			get_size_cmd(t_token *lst_token)
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

char		**create_cmd_args(t_token **lst_token, int size)
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
	if((*lst_token) && (*lst_token)->type == space)
		*lst_token = (*lst_token)->next;
	cmd[i] = NULL;
	return (cmd);
}

void		exec_cmd(t_cmd *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		perror("fork");
	else if (pid > 0)
		while(wait(NULL) != -1 && errno != ECHILD);
	else
	{
		do_redir(cmd->redir_type, cmd->redir_fd);
		if (execve(cmd->args[0], cmd->args, g_sh.env) == -1)
			exit(EXIT_FAILURE);
	}
	if (cmd->redir_type != nope)
		close(cmd->redir_fd);
}
