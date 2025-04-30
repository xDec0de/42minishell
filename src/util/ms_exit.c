/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:46:52 by daniema3          #+#    #+#             */
/*   Updated: 2025/04/30 20:59:45 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ms_free(t_shell	*shell)
{
	if (shell == NULL)
		return ;
	free(shell);
}

void	ms_exit(int code, char *err)
{
	ms_free(get_shell());
	if (err != NULL)
		printf("%s", err);
	exit(code);
}
