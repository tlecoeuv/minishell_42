/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:18:26 by tanguy            #+#    #+#             */
/*   Updated: 2020/10/09 03:28:22 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		handle_commands(t_token *lst_token)
{
	while(lst_token)
	{
		handle_one_command(&lst_token);
	}
}

handle_one_command(char **lst_token)
{
	while (*lst_token && *lst_token->type != sm_cl)
	{
		
	}
}

char		**token_to_tab(t_token lst_token)
{

}

void		exec_cmd(char **cmd)
{

}

//while(wait(NULL) != -1 && errno != ECHILD);
