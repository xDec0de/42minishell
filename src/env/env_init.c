/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:59:09 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/04 12:23:36 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	increment_shlvl(t_shell *shell)
{
	t_env	*shlvl;
	int		i_new_lvl;
	char	*new_lvl;
	char	*new_shlvl;

	shlvl = env_get(shell, "SHLVL");
	if (shlvl == NULL || !ms_strisnumeric(shlvl->value, false))
	{
		env_export(shell, "SHLVL=1");
		return ;
	}
	i_new_lvl = ms_atoi(shlvl->value) + 1;
	if (i_new_lvl < 0)
		i_new_lvl = 0;
	new_lvl = ms_itoa(i_new_lvl);
	new_shlvl = ms_strjoin("SHLVL", new_lvl, '=');
	free(new_lvl);
	env_export(shell, new_shlvl);
	free(new_shlvl);
}

void	env_init(t_shell *shell, char **env)
{
	t_ulong	i;

	i = 0;
	if (env == NULL)
		return ;
	while (env[i] != NULL)
	{
		env_export(shell, env[i]);
		i++;
	}
	increment_shlvl(shell);
}
