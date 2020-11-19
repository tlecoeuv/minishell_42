/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:18:26 by tanguy            #+#    #+#             */
/*   Updated: 2020/11/19 11:39:20 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		handle_tokens(t_token *lst_token)
{
	t_cmd	**cmds;
	int		nb_cmds;

	while (lst_token)
	{
		cmds = get_commands(&lst_token, &nb_cmds);
		if (nb_cmds > 0)
		{
			if (nb_cmds == 1)
				handle_command_no_pipe(cmds[0]);
			else
				handle_commands_pipe(cmds, nb_cmds);
		}
		free_commands(cmds);
		free(cmds);
	}
}
