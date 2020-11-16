/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:55:06 by tanguy            #+#    #+#             */
/*   Updated: 2020/11/16 16:55:09 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		handle_sigint(int code)
{
	(void)code;
	if (g_sig.pid == 0)
	{
		ft_putstr_fd("\b\b  ", STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		ft_putstr_fd("minishell: >", STDERR_FILENO);
		g_sh.status = STATUS_CTRL_C;
	}
	else
		ft_putstr_fd("\n", STDERR_FILENO);
	g_sh.status = STATUS_CTRL_C;
	g_sig.sigint = 1;
}

void		handle_sigquit(int code)
{
	(void)code;
	if (g_sig.pid != 0)
	{
		ft_putstr_fd("Quit: (core dumped)\n", STDERR_FILENO);
		g_sig.sigquit = 1;
		g_sh.status = STATUS_CTRL_BACKSLASH;
	}
	else
		ft_putstr_fd("\b\b  \b\b", STDERR_FILENO);
}

void		reset_sig(void)
{
	g_sig.sigint = 0;
	g_sig.sigquit = 0;
}
