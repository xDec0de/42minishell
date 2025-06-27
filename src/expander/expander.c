/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 21:11:00 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/27 13:30:40 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_expanded_value(t_shell *shell, char *str, t_ulong from)
{
	t_ulong	size;
	t_env	*env;
	char	*key;

	size = 0;
	while (str[from + size] != ' ' && str[from + size] != '\0')
		size++;
	key = ms_substr(str, from, size);
	if (ms_strequals(key, "?"))
	{
		if (shell->last_cmd == NULL)
			return (free(key), ms_strdup("0"));
		return (free(key), ms_itoa(shell->last_cmd->exit_code));
	}
	env = env_get(shell, key);
	free(key);
	if (env != NULL)
		return (ms_strdup(env->value));
	return (ms_strdup(""));
}
