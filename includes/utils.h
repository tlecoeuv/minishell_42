/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:09:23 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/10/05 16:35:51 by tlecoeuv         ###   ########.fr       */
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

#endif
