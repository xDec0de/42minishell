/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:22:17 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/05 11:22:07 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_prompt(t_shell *shell)
{
	char	*prompt;
	char	*pwd;

	pwd = get_pwd(shell);
	if (pwd == NULL)
		pwd = ".";
	prompt = ms_strreplace(SHELL_PROMPT, 10, 1, pwd);
	return (prompt);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	*shell;
	char	*prompt;

	(void) argc;
	(void) argv;
	shell = init_shell(envp);
	init_sighandler();
	while (true)
	{
		if (shell->last_input != NULL)
			free(shell->last_input);
		prompt = get_prompt(shell);
		shell->last_input = readline(prompt);
		free(prompt);
		if (shell->last_input == NULL)
			ms_exit(EXEC_OK, NULL);
		handle_cmd_input(shell);
		add_history(shell->last_input);
	}
}
