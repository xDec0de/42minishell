/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 21:06:53 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/27 21:21:47 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*bltn_export(t_shell *shell, char **args)
{
	if (args[0] == NULL)
		return (bltn_env(shell));
	else
		env_export(shell, args[0]);
	return (build_cmd(EXEC_OK, NULL, true));
}
