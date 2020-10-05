/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:46:08 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/10/05 16:55:45 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"

int		main(int argc, char **argv)
{
	char	*cmd;

	(void)argc;
	cmd = ft_strdup(argv[1]);
	get_absolute_path(&cmd);
	printf("%s\n", cmd);
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
		free(path);
		while (path_split[i])
		{
			printf("%d\npath_split[i]:%s\ncmd:%s\n", i, path_split[i], *cmd);
			if(!(bin = malloc(sizeof(char) * (ft_strlen(path_split[i]) + ft_strlen(*cmd) + 2))))
				break ;
			printf("yo\n");
			ft_strcat(bin, path_split[i]);
			ft_strcat(bin, "/");
			ft_strcat(bin, *cmd);
			printf("bin: %s\n", bin);
			if (test_file(bin))
				break ;
			free(bin);
		//	bin = NULL;
			i++;
		}
		printf("out of while\n");
		free_array(path_split);
		free(*cmd);
		*cmd = bin;
	}
	else
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
