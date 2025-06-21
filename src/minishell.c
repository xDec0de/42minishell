/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:22:17 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/21 12:56:49 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_prompt(void)
{
	char	*prompt;
	char	pwd[PATH_MAX];

	getcwd(pwd, PATH_MAX);
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
	while (shell->running)
	{
		if (shell->last_input != NULL)
			free(shell->last_input);
		prompt = get_prompt();
		shell->last_input = readline(prompt);
		free(prompt);
		if (shell->last_input == NULL)
			ms_exit(EXEC_OK, NULL);
		shell->last_cmd = parse_cmd_input(shell);
		add_history(shell->last_input);
	}
	if (shell->last_cmd != NULL)
		ms_exit(shell->last_cmd->exit_code, NULL);
	ms_exit(EXEC_OK, NULL);
}
