/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 11:05:06 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/11/09 18:23:41 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		error_cmd_not_found(char *cmd)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	g_sh.status = STATUS_CMD_NOT_FOUND;
	return (0);
}

void	error(char *cmd, char *arg)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (cmd)
	{
		ft_putstr_fd(cmd, STDERR_FILENO);
		write(STDERR_FILENO, ": ", 2);
	}
	if (arg)
	{
		ft_putstr_fd(arg, STDERR_FILENO);
		write(STDERR_FILENO, ": ", 2);
	}
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	write(STDERR_FILENO, "\n", 1);
}
