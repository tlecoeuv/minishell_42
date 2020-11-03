/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:24:07 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/10/30 14:56:25 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		is_builtin(char	*str)
{
	int			i;
	const char	*builtin_str[] = {"cd", "exit", "pwd", "env"};

	i = 0;
	while (i < 4)
	{
		if (ft_strcmp(builtin_str[i], str) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	exec_builtin(t_cmd *cmd)
{
	int			i;
	const char	*builtin_str[] = {"cd", "exit", "pwd", "env"};
	void		(*builtin_func[4])(char **);
	int			save_stdin;
	int			save_stdout;

	i = 0;
	builtin_func[0] = &ft_cd;
	builtin_func[1] = &ft_exit;
	builtin_func[2] = &ft_pwd;
	builtin_func[3] = &ft_env;

	builtin_redir(cmd->in_fd, cmd->out_fd, &save_stdin, &save_stdout);
	while (i < 4)
	{
		if (ft_strcmp(builtin_str[i], cmd->args[0]) == 0)
		{
			builtin_func[i](cmd->args);
			break ;
		}
		i++;
	}
	restore_savefd(cmd->in_fd, cmd->out_fd, save_stdin, save_stdout);
}
