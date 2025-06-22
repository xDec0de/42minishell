/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:59:09 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/22 13:51:08 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_init(t_shell *shell, char **env)
{
	t_ulong	i;

	i = 0;
	while (env[i] != NULL)
	{
		env_export(shell, env[i]);
		i++;
	}
}
