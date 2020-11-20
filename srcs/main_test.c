/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:50:24 by tanguy            #+#    #+#             */
/*   Updated: 2020/11/02 17:52:21 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_shell	g_sh;
t_sig	g_sig;

int		main(int argc, char **argv, char **envp)
{
	t_token	*tokens;
	char	*input;


	(void)argc;
	(void)input;
	init_shell(envp);
	set_env_var("PWD", g_sh.cwd);
	//while (g_sh.running)
	//{
			//write(1, "minishell: >", 12);
			//get_next_line(0, &input);
			create_tokens_list(argv[2], &tokens);
			if (check_syntax(tokens))
				handle_tokens(tokens);
			tok_lstclear(&tokens);
			//free(input);
	//}
	free_array(g_sh.env);
	free(g_sh.cwd);
	return (g_sh.status);
}

//gcc env/*.c exec/*.c get_next_line/*.c syntax/*.c tokens/*.c tokens/token_list_utils/*.c utils/*.c builtins/*.c main.c
