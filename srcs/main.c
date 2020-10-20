/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:50:24 by tanguy            #+#    #+#             */
/*   Updated: 2020/10/20 18:50:06 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_shell	g_sh;

int		main(int argc, char **argv, char **envp)
{
	t_token	*tokens;
	char	*input;

	init_shell(envp);
	while (g_sh.running)
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

//gcc env/*.c exec/*.c get_next_line/*.c syntax/*.c tokens/*.c tokens/token_list_utils/*.c utils/*.c builtins/*.c main.c
