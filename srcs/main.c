/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:50:24 by tanguy            #+#    #+#             */
/*   Updated: 2020/10/20 03:43:41 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**g_env;

int		main(int argc, char **argv, char **envp)
{
	t_token	*tokens;
	char	*input;

	init_env(envp);
	while (1)
	{
			write(1, "minishell: >", 12);
			get_next_line(0, &input);
			create_tokens_list(input, &tokens);
			check_syntax(tokens);
			handle_tokens(tokens);
			tok_lstclear(&tokens);
			free(input);
	}
	return (0);
}

//Pour compiler:
//gcc env/*.c exec/*.c get_next_line/*.c parsing/*.c parsing/token_list_utils/*.c utils/*.c main.
