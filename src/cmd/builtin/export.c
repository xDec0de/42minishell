/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 21:06:53 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/29 18:48:27 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bltn_export(t_shell *shell, char **args)
{
	if (args[0] == NULL)
		print_env(shell);
	else
		env_export(shell, args[0]);
	return (EXEC_OK);
}
