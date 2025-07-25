/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:22:17 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/25 00:11:18 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_prompt(t_shell *shell)
{
	char	*prompt;
	char	*pwd;
	char	*colored_pwd;
	char	*tmp;

	pwd = get_pwd(shell);
	if (pwd == NULL)
		pwd = ".";
	colored_pwd = ms_strjoin("\033[94m", pwd, '\0');
	tmp = colored_pwd;
	colored_pwd = ms_strjoin(colored_pwd, "\033[0m", '\0');
	free(tmp);
	tmp = ms_strjoin("\033[92mminishell\033[0m: ", colored_pwd, '\0');
	free(colored_pwd);
	prompt = ms_strjoin(tmp, " $ ", '\0');
	free(tmp);
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
