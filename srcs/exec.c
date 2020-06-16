/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 17:55:45 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/06/16 11:41:52 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		exec_args(char **args)
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

int		exec_argspiped(char **args, char **argspiped)
{
	int		pipefd[2];
	pid_t	pid1, pid2;
	printf("enter exec_argspiped\n");

	if (pipe(pipefd) < 0)
	{
		printf("Pipe could not be initialized\n");
		return (1);
	}
	pid1 = fork();
	if (pid1 < 0)
	{
		printf("\nCould not fork"); 
        return (1);
	} 
	if (pid1 == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		if (execvp(args[0], args) < 0)
		{
			printf("\nCould not execute command 1..");
            exit(0);
        }
	}
	else
	{
		pid2 = fork();
		if (pid2 < 0)
		{
			printf("\nCould not fork");
            return (1);
        }
		if (pid2 == 0)
		{
			close(pipefd[1]);
			dup2(pipefd[0], STDIN_FILENO);
			close(pipefd[0]);
			if (execvp(argspiped[0], argspiped) < 0)
			{
				printf("\nCould not execute command 2..");
                exit(0);
            }
		}
		else
		{
			wait(NULL);
		}
	}
	return (1);
}
