/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:24:07 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/10/28 17:12:23 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		is_builtin(char	*str)
{
	int			i;
	const char	*builtin_str[] = {"cd", "exit", "pwd"};

	i = 0;
	while (i < 3)
	{
		if (ft_strcmp(builtin_str[i], str) == 0)
			return (1);
		i++;
	}
	return (0);
}

void exec_builtin(t_cmd *cmd)
{
	int			i;
	const char	*builtin_str[] = {"cd", "exit", "pwd"};
	void		(*builtin_func[3])(char **);
	int			savefd;

	i = 0;
	builtin_func[0] = &ft_cd;
	builtin_func[1] = &ft_exit;
	builtin_func[2] = &ft_pwd;

	do_builtin_redir(cmd->redir_type, cmd->redir_fd, &savefd);
	while (i < 3)
	{
		if (ft_strcmp(builtin_str[i], cmd->args[0]) == 0)
		{
			builtin_func[i](cmd->args);
			break ;
		}
		i++;
	}
	restore_savefd(cmd->redir_type, cmd->redir_fd, savefd);
}

void			do_builtin_redir(t_type redir_type, int fd, int *savefd)
{
	if (redir_type == out || redir_type == append_out)
	{
		*savefd = dup(STDOUT_FILENO);
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	else if (redir_type == in)
	{
		*savefd = dup(STDIN_FILENO);
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
}

void			restore_savefd(t_type redir_type, int redir_fd, int savefd)
{
	if (redir_type == out || redir_type == append_out)
	{
		close(redir_fd);
		dup2(savefd, STDOUT_FILENO);
		close(savefd);
	}
	else if (redir_type == in)
	{
		close(redir_fd);
		dup2(savefd, STDIN_FILENO);
		close(savefd);
	}
}
