/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 21:11:00 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/27 15:05:04 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_ulong	get_key_size(char *str, t_ulong from)
{
	t_ulong	size;

	size = 0;
	while (str[from + size] != ' ' && str[from + size] != '\0')
		size++;
	return (size);
}

char	*get_expanded_value(t_shell *shell, char *str, t_ulong from)
{
	t_env	*env;
	char	*key;

	key = ms_substr(str, from, get_key_size(str, from));
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

t_ulong	get_expanded_size(t_shell *shell, char *str)
{
	t_ulong	i;
	t_ulong	size;
	char	*value;
	bool	on_quote;

	on_quote = false;
	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'')
			on_quote = !on_quote;
		else if (!on_quote && str[i] == '$')
		{
			value = get_expanded_value(shell, str, i + 1L);
			size += ms_strlen(value);
			i += get_key_size(str, i + 1);
			free(value);
		}
		else
			size++;
		i++;
	}
	return (size);
}
