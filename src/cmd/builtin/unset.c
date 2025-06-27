/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 01:05:35 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/27 21:21:58 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*bltn_unset(t_shell *shell, char **args)
{
	if (args[0] != NULL)
		env_unset(shell, args[0]);
	return (build_cmd(EXEC_OK, NULL, true));
}
