/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:09:23 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/11/30 20:55:53 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <sys/types.h>

int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isspace(int c);
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
char				*ft_strjoin(char *s1, char *s2);
char				*ft_substr(const char *str, unsigned int start, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_strchr(char *str, int c);
int					get_len_valid_identifier(char *str);
char				*ft_strtrim(char const *s1, char const *set);
void				ft_putstr_fd(char *s, int fd);
void				manage_env_path();
char				*ft_itoa(int n);
int					ft_atoi(const char *str);
int					get_input(char **input);

#endif
