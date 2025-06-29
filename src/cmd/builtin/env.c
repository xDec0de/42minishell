/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:10:16 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/30 01:13:09 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_env(t_shell *shell)
{
	t_env	*env;

	env = shell->env;
	while (env != NULL)
	{
		printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
	return (EXEC_OK);
}

void	bltn_env(t_shell *shell)
{
	ms_exit(print_env(shell), NULL);
}
