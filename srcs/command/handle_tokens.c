/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:18:26 by tanguy            #+#    #+#             */
/*   Updated: 2020/11/13 11:38:47 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		handle_tokens(t_token *lst_token)
{
	t_cmd	**cmds;
	int		i;
	int		nb_cmds;

	i = 0;
	while (lst_token)
	{
		cmds = get_commands(&lst_token, &nb_cmds);
		if (nb_cmds == 1)
			handle_command_no_pipe(cmds[0]);
		else
			handle_commands_pipe(cmds, nb_cmds);
		while (cmds[i])
		{
			free_array(cmds[i]->args);
			free(cmds[i]);
			i++;
		}
		free(cmds);
	}
}
