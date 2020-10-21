/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 11:03:36 by tlecoeuv          #+#    #+#             */
/*   Updated: 2020/10/21 23:02:11 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define STATUS_SUCCESS				0
# define STATUS_FAILURE 			1
# define STATUS_FAILURE_BUILTIN 	2
# define STATUS_NOT_EXECUTABLE		126
# define STATUS_CMD_NOT_FOUND		127
# define STATUS_EXIT_INVALID_ARGS	128
# define STATUS_CTRL_C				130
# define STATUS_CTRL_BACKSLASH		131

void	error_cmd_not_found(char *cmd);
void	error(char *cmd, char *arg);

#endif
