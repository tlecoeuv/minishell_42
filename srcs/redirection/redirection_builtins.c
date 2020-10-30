/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_builtins.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:09:30 by tanguy            #+#    #+#             */
/*   Updated: 2020/10/30 14:57:23 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	builtin_redir(int in_fd, int out_fd, int *save_stdin, int *save_stdout)
{
	if (out_fd > 0)
	{
		*save_stdout = dup(STDOUT_FILENO);
		dup2(out_fd, STDOUT_FILENO);
		close(out_fd);
	}
	else if (in_fd > 0)
	{
		*save_stdin = dup(STDIN_FILENO);
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
	}
}

void	restore_savefd(int in_fd, int out_fd, int save_stdin, int save_stdout)
{
	if (out_fd > 0)
	{
		close(out_fd);
		dup2(save_stdout, STDOUT_FILENO);
		close(save_stdout);
	}
	else if (in_fd > 0)
	{
		close(in_fd);
		dup2(save_stdin, STDIN_FILENO);
		close(save_stdin);
	}
}
