/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:22:17 by daniema3          #+#    #+#             */
/*   Updated: 2025/04/07 18:15:23 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*get_shell(t_shell *init)
{
	static t_shell	*shell;

	if (init != NULL)
		shell = init;
	return (shell);
}

t_shell	*init_shell(void)
{
	t_shell	*shell;

	shell = malloc(sizeof(t_shell));
	shell->running = true;
	return (get_shell(shell));
}

int	main(void)
{
	t_shell *shell;

	shell = init_shell();
	while (shell->running)
	{
		readline("minishell: ");
	}
	return (0);
}
