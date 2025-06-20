/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 01:02:38 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/21 01:02:53 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*env_get(t_shell *shell, char *key)
{
	t_env	*tmp;

	tmp = shell->env;
	while (tmp != NULL)
	{
		if (ms_strequals(key, tmp->key))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
