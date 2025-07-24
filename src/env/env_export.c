/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:03:09 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/24 19:08:44 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_addnew(t_shell *shell, char *key, char *value)
{
	t_env	*tmp;
	t_env	*new;

	new = ms_malloc(sizeof(t_env));
	new->key = key;
	new->value = value;
	new->next = NULL;
	tmp = shell->env;
	if (tmp == NULL)
		shell->env = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

static bool	check_env_chars(const char *key)
{
	t_ulong	i;

	i = 0;
	while (key[i] != '\0')
	{
		if (!ms_isenvkeychar(key[i]))
		{
			ms_print(FD_ERR, "minishell: export: `");
			ms_print(FD_ERR, key);
			ms_print(FD_ERR, "`: not a valid identifier\n");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	env_export(t_shell *shell, char *env)
{
	char	*key;
	t_env	*node;
	char	*equal;

	equal = ms_strchr(env, '=');
	if (equal == NULL)
		return (false);
	key = ms_substr(env, 0, equal - env);
	if (!check_env_chars(key))
		return (free(key), false);
	node = env_get(shell, key);
	if (node != NULL)
	{
		free(key);
		free(node->value);
		node->value = ms_strdup(equal + 1);
		return (true);
	}
	env_addnew(shell, key, ms_strdup(equal + 1));
	return (true);
}
