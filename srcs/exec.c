/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 17:55:45 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/06/15 23:14:06 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		execute_command(char **args)
{
	int			i;
	const char	*builtin_str[] = {"cd", "exit"};
	int			(*builtin_func[2])(char **);

	i = 0;
	builtin_func[0] = &ft_cd;
	builtin_func[1] = &ft_exit;
	if (args[0] == NULL)
		return (1);
	while (i < 2)
	{
		if (ft_strcmp(args[0], builtin_str[i]) == 0)
			return (builtin_func[i](args));
		i++;
	}
	return (launch_process(args));
}

int		launch_process(char **args)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
			perror("lsh");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("lsh");
	else
		wait(NULL);
	return (1);
}
