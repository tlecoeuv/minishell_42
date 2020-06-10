/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 22:02:45 by tlecoeuv          #+#    #+#             */
/*   Updated: 2019/11/05 21:27:44 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *str);
int		ft_strchr(char *str, int c);
char	*ft_str_dup_line(char *str);
char	*ft_create_str(int size);
int		ft_reduce_static_tab(char **static_str);
char	*ft_str_cat_dup(char *str, char *buff);
int		get_next_line(int fd, char **line);

#endif
