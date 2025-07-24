/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 21:06:53 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/24 18:23:35 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bltn_export(t_shell *shell, char **args)
{
	if (args[0] != NULL)
		return (!env_export(shell, args[0]));
	print_env(shell);
	return (EXEC_OK);
}
