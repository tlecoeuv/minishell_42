/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:50:24 by tanguy            #+#    #+#             */
/*   Updated: 2020/11/13 11:54:46 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_shell	g_sh;

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
		get_next_line(0, &input);
		create_tokens_list(input, &tokens);
		if (check_syntax(tokens))
			handle_tokens(tokens);
		tok_lstclear(&tokens);
		free(input);
	}
	return (g_sh.status);
}
