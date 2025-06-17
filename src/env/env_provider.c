/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_provider.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:59:09 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/17 17:57:43 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_env_back(t_env **lst, t_env *new)
{
	t_env	*temp;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

t_env	*create_env_node(char *env)
{
	t_env	*node;
	char	*equal;
	size_t	key_len;

	node = ms_malloc(sizeof(t_env));
	equal = ms_strchr(env, '=');
	if (equal == NULL)
		return (free(node), NULL);
	key_len = equal - env;
	node->key = ms_substr(env, 0, key_len);
	node->value = ms_strdup(equal + 1);
	node->next = NULL;
	return (node);
}

t_env	*init_env(char **env)
{
	t_env	*env_list;
	t_env	*node;
	int		i;

	i = 0;
	env_list = NULL;
	while (env[i] != NULL)
	{
		node = create_env_node(env[i]);
		if (node)
			add_env_back(&env_list, node);
		i++;
	}
	return (env_list);
}
