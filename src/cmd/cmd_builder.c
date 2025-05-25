/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:34:16 by daniema3          #+#    #+#             */
/*   Updated: 2025/05/25 22:36:02 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd	*build_cmd(int exit_code, char *output)
{
	t_cmd	*cmd;

	cmd = ms_malloc(sizeof(t_cmd));
	cmd->exit_code = exit_code;
	cmd->output = output;
	return (cmd);
}
