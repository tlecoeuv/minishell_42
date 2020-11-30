/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:50:24 by tanguy            #+#    #+#             */
/*   Updated: 2020/11/30 20:53:47 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_shell	g_sh;
t_sig	g_sig;

int		main(int argc, char **argv, char **envp)
{
	t_token	*tokens;
	char	*input;

	(void)argv;
	(void)argc;
	init_shell(envp);
	set_env_var("PWD", g_sh.cwd);
	while (g_sh.running)
	{
		write(1, "minishell: >", 12);
		if (get_input(&input))
		{
			create_tokens_list(input, &tokens);
			if (check_syntax(tokens))
				handle_tokens(tokens);
			tok_lstclear(&tokens);
		}
		reset_sig();
		free(input);
	}
	free_array(g_sh.env);
	free(g_sh.cwd);
	write(1, "exit\n", 5);
	return (g_sh.status);
}
