/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 11:28:44 by tanguy            #+#    #+#             */
/*   Updated: 2020/06/05 14:38:22 by tanguy           ###   ########.fr       */
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
	int		status;
	char	**args;

	status = 1;
	while (status)
	{
		write(1, "> ", 2);
		read_command(args);
//		status = execute_command(args);
		status = 1;
		free(args);
	}
}
