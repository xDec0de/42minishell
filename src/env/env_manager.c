/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:59:09 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/20 21:03:04 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_free(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env->next;
		free(env->key);
		free(env->value);
		free(env);
		env = tmp;
	}
}

t_env*	env_get(t_shell *shell, char *key)
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

bool	env_export(t_shell *shell, char *env)
{
	char	*key;
	t_env	*node;
	char	*equal;

	equal = ms_strchr(env, '=');
	if (equal == NULL)
		return (false);
	key = ms_substr(env, 0, equal - env);
	node = env_get(shell, key);
	if (node != NULL)
	{
		free (node->value);
		node->value = ms_strdup(equal + 1);
		return (true);
	}
	env_addnew(shell, key, ms_strdup(equal + 1));
	return (true);
}

void	env_init(t_shell *shell, char **env)
{
	size_t	i;

	i = 0;
	while (env[i] != NULL)
	{
		env_export(shell, env[i]);
		i++;
	}
}
