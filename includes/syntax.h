/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: austin <avieira@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 02:29:39 by austin            #+#    #+#             */
/*   Updated: 2020/10/20 03:24:48 by austin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_H
# define SYNTAX_H

# define SYNTAX_ERROR_MSG "minishell: syntax error near unexpected token `"

int		check_syntax(t_token *tokens);
int		syntax_error(char *str_token);

int		check_pip(t_token *tokens, t_token *go);
int		check_in(t_token *tokens, t_token *go);
int		check_out(t_token *tokens, t_token *go);
int		check_append_out(t_token *tokens, t_token *go);
int		check_word(t_token *tokens, t_token *go);
int		check_space(t_token *tokens, t_token *go);
int		check_v_env(t_token *tokens, t_token *go);
int		check_end(t_token *tokens, t_token *go);
int		check_nope(t_token *tokens, t_token *go);

#endif
