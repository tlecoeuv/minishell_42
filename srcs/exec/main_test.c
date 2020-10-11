/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:50:24 by tanguy            #+#    #+#             */
/*   Updated: 2020/10/11 16:02:06 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**g_env;

int		main(int argc, char **argv, char **envp)
{
	t_token	*lst_token;
	t_token	*tmp;
	int		i;

	i = 3;
	init_env(envp);
	lst_token = tok_lstnew(argv[1]);
	lst_token->type = ft_atoi(argv[2]);
	while (i < argc)
	{
		tmp = tok_lstnew(argv[i]);
		tmp->type = ft_atoi(argv[i + 1]);
		if (lst_token->next)
			printf("WTFF\n");
		tok_lstadd_back(&lst_token, tmp);
		i += 2;
	}
	printf("lst_token created!\n");
	handle_tokens(lst_token);
	return (0);
}
