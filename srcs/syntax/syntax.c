/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 02:10:06 by austin            #+#    #+#             */
/*   Updated: 2020/10/20 03:41:15 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			syntax_error(char *str_token)
{
	write(1, SYNTAX_ERROR_MSG, ft_strlen(SYNTAX_ERROR_MSG));
	write(1, str_token, ft_strlen(str_token));
	write(1, "'\n", 2);
	return (ERROR);
}

int			check_syntax(t_token *tokens)
{
	t_token		*go;
	int			(*check_type[9])(t_token *, t_token *);

	check_type[0] = &check_pip;
	check_type[1] = &check_in;
	check_type[2] = &check_out;
	check_type[3] = &check_append_out;
	check_type[4] = &check_word;
	check_type[5] = &check_space;
	check_type[6] = &check_v_env;
	check_type[7] = &check_end;
	check_type[8] = &check_nope;

	go = tokens;
	while (go)
	{
		if (check_type[go->type](tokens, go) == ERROR)
			return (ERROR);
		go = go->next;
	}
	return (SUCCESS);
}
