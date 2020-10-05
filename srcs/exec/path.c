/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:46:08 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/10/05 23:20:03 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"

int		main(int argc, char **argv, char **envp)
{
	char	*cmd;
	int		i;

	i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
	(void)argc;
	cmd = ft_strdup(argv[1]);
	get_absolute_path(&cmd);
	printf("RESULT:%s\n", cmd);
	return (0);
}

void	get_absolute_path(char **cmd)
{
	char    *path;
	char    *bin;
	char    **path_split;
	int     i;

	i = 0;
	path = ft_strdup(getenv("PATH"));
	if (**cmd != '/' && ft_strncmp(*cmd, "./", 2) != 0)
	{
		path_split = ft_split(path, ':');
		while (path_split[i])
		{
			if(!(bin = ft_calloc(sizeof(char), (ft_strlen(path_split[i]) + ft_strlen(*cmd) + 2))))
				break ;
			ft_strcat(bin, path_split[i]);
			ft_strcat(bin, "/");
			ft_strcat(bin, *cmd);
			if (test_file(bin))
				break ;
			free(bin);
			bin = NULL;
			i++;
		}
		free_array(path_split);
		free(*cmd);
		*cmd = bin;
	}
	free(path);
}

int		test_file(char *file_name)
{
	struct stat	buffer;
	int			exist;

	exist = stat(file_name, &buffer);
	if (exist == 0)
		return (1);
	else
		return (0);
}
