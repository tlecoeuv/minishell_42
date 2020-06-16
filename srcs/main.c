/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 11:28:44 by tanguy            #+#    #+#             */
/*   Updated: 2020/06/16 11:33:09 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		main()
{
	big_loop();
	return (EXIT_SUCCESS);
}

void	big_loop(void)
{
	char	**args;
	char	**argspiped;
	int		status;

	status = 1;
	while (status)
	{
		write(1, "> ", 2);
		parse_command(&args, &argspiped);
		if (!argspiped)
			status = exec_args(args);
		else
		{
			status = exec_argspiped(args, argspiped);
			free(argspiped);
		}
		free(args);
	}
}
