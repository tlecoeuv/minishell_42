/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:09:23 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/10/08 19:00:38 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <sys/types.h>

int					ft_isalnum(int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strlen(const char *s1);
char				**ft_split(char const *s, char c);
char				*ft_strcat(char *dest, char *src);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				free_array(char	**array);
char				*ft_strdup(char *src);
void				*ft_calloc(size_t count, size_t size);
int					get_array_size(char **array);
char				*ft_strjoin_sep(char *s1, char *s2, char sep);

//temporaire
int					ft_atoi(const char *str);

#endif