/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:15:26 by rexposit          #+#    #+#             */
/*   Updated: 2025/06/30 15:38:15 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include "minishell.h"

static char	*search_in_paths(char **paths, char *cmd)
{
	char	*full_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		full_path = ms_strjoin(paths[i], cmd, '/');
		if (!full_path)
			break ;
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*get_cmd_from_path(t_shell *shell, char *cmd)
{
	t_env	*path_node;
	char	**paths;
	char	*full_path;

	if (!cmd || ms_strchr(cmd, '/'))
		return (ms_strdup(cmd));
	path_node = env_get(shell, "PATH");
	if (!path_node || !path_node->value)
		return (NULL);
	paths = ms_split(path_node->value, ':');
	if (!paths)
		return (NULL);
	full_path = search_in_paths(paths, cmd);
	ms_arrfree(paths);
	return (full_path);
}
