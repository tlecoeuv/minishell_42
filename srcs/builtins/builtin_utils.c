/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:24:07 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/10/19 14:32:50 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		is_builtin(char	*str)
{
	int			i;
	const char	*builtin_str[] = {"cd", "exit"};

	i = 0;
	while (i < 2)
	{
		if (ft_strcmp(str, builtin_str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void exec_builtin(t_cmd *cmd)
{
	int			i;
	const char	*builtin_str[] = {"cd", "exit"};
	void		(*builtin_func[2])(char **);

	i = 0;
	builtin_func[0] = &ft_cd;
	builtin_func[1] = &ft_exit;

	while (i < 2)
	{
		if (ft_strcmp(cmd->args[0], builtin_str[i]) == 0)
		{
			builtin_func[i](cmd->args);
			return ;
		}
		i++;
	}
}
