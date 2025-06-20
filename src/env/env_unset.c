/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 23:11:32 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/21 00:53:50 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	env_unset(t_shell *shell, char *key)
{
	t_env	*tmp;
	t_env	*to_free;

	tmp = shell->env;
	if (tmp == NULL)
		return (false);
	if (tmp->next == NULL && ms_strequals(tmp->key, key))
		return (env_free(shell), true);
	while (tmp->next != NULL)
	{
		if (ms_strequals(tmp->next->key, key))
		{
			to_free = tmp->next;
			tmp->next = to_free->next;
			free(to_free->key);
			free(to_free->value);
			free(to_free);
			return (true);
		}
		tmp = tmp->next;
	}
	return (false);
}
