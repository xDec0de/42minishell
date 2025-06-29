/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 01:05:35 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/29 17:48:21 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bltn_unset(t_shell *shell, char **args)
{
	if (args[0] != NULL)
		env_unset(shell, args[0]);
	ms_exit(EXEC_OK, NULL);
}
