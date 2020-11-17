/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:50:24 by tanguy            #+#    #+#             */
/*   Updated: 2020/11/15 12:57:44 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_shell	g_sh;
t_sig	g_sig;

int		main(int argc, char **argv, char **envp)
{
	t_token	*tokens;
	char	*input;
	int		ret;

	(void)argv;
	(void)argc;
	init_shell(envp);
	set_env_var("PWD", g_sh.cwd);
	while (g_sh.running)
	{
		write(1, "minishell: >", 12);
		ret = get_next_line(0, &input);
		create_tokens_list(input, &tokens);
		if (check_syntax(tokens))
			handle_tokens(tokens);
		tok_lstclear(&tokens);
		if (ret == 0)
			g_sh.running = 0;
		reset_sig();
		free(input);
	}
	free_array(g_sh.env);
	free(g_sh.cwd);
	write(1, "exit\n", 5);
	return (g_sh.status);
}
