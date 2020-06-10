/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 22:01:57 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/06/04 17:25:45 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

#define BUFFER_SIZE 1000

int		ft_reduce_static_tab(char **static_str)
{
	int		i;
	int		j;

	i = 0;
	if ((j = ft_strchr(*static_str, '\n')) >= 0)
	{
		j++;
		while ((*static_str)[i + j])
		{
			(*static_str)[i] = (*static_str)[i + j];
			i++;
		}
		(*static_str)[i] = '\0';
		return (1);
	}
	if (*static_str != NULL)
	{
		free(*static_str);
		*static_str = NULL;
	}
	return (0);
}

char	*ft_str_cat_dup(char *str, char *buff)
{
	char	*copy;
	int		i;
	int		j;
	int		size_str;
	int		size_buff;

	i = 0;
	j = 0;
	size_str = ft_strlen(str);
	size_buff = ft_strlen(buff);
	if (!(copy = malloc(sizeof(char) * (size_str + size_buff + 1))))
		return (NULL);
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	while (buff[j])
	{
		copy[i + j] = buff[j];
		j++;
	}
	copy[i + j] = '\0';
	return (copy);
}

int		get_next_line(int fd, char **line)
{
	static char *static_tab[1024];
	char		buff[BUFFER_SIZE + 1];
	int			ret;
	char		*tmp;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	if (static_tab[fd] == NULL && (static_tab[fd] = ft_create_str(0)) == NULL)
		return (-1);
	while (ft_strchr(static_tab[fd], '\n') == -1 &&
		(ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_str_cat_dup(static_tab[fd], buff);
		free(static_tab[fd]);
		static_tab[fd] = tmp;
	}
	*line = ft_str_dup_line(static_tab[fd]);
	if (!ft_reduce_static_tab(&(static_tab[fd])))
		return (0);
	return (1);
}
