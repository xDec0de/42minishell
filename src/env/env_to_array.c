/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:51:38 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/27 20:00:09 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_to_array(t_shell *shell)
{
	t_ulong	i;
	t_ulong	size;
	char	**env;
	t_env	*tmp;

	size = env_size(shell);
	env = ms_malloc(size + 1);
	env[size] = NULL;
	if (size == 0)
		return (env);
	tmp = shell->env;
	while (tmp != NULL)
	{
		env[i] = ms_strjoin(tmp->key, tmp->value, '=');
		tmp = tmp->next;
		i++;
	}
	return (env);
}
