/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 21:06:53 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/29 17:47:48 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bltn_export(t_shell *shell, char **args)
{
	if (args[0] == NULL)
		bltn_env(shell);
	else
		env_export(shell, args[0]);
	ms_exit(EXEC_OK, NULL);
}
