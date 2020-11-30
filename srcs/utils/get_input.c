/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:32:31 by tanguy            #+#    #+#             */
/*   Updated: 2020/11/30 21:08:20 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			get_input(char **input)
{
	char	*tmp;
	char	*to_free;
	int		ret;

	if ((ret = get_next_line(0, input)) == 1)
		return (1);
	else if (ret == 0 && ft_strlen(*input) != 0)
	{
		while (get_next_line(0, &tmp) == 0)
		{
			to_free = *input;
			*input = ft_strjoin(*input, tmp);
			free(to_free);
			free(tmp);
		}
		to_free = *input;
		*input = ft_strjoin(*input, tmp);
		free(to_free);
		free(tmp);
		return (1);
	}
	g_sh.running = 0;
	return (0);
}
