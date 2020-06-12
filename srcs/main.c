/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 11:28:44 by tanguy            #+#    #+#             */
/*   Updated: 2020/06/12 18:12:23 by tlecoeuv         ###   ########.fr       */
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

	while (1)
	{
		write(1, "> ", 2);
		parse_command(&args);
		execute_command(args);
		free(args);
	}
}
