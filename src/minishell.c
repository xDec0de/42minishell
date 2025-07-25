/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:22:17 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/25 16:09:39 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cut_home(t_shell *shell, const char *pwd)
{
	t_env	*home;
	t_ulong	home_len;

	home = env_get(shell, "HOME");
	if (home == NULL || home->value == NULL)
		return (ms_strdup(pwd));
	home_len = ms_strlen(home->value);
	if (ms_strequals(pwd, home->value))
		return (ms_strdup("~"));
	if (ms_strncmp(pwd, home->value, home_len) == 0 && pwd[home_len] == '/')
		return (ms_strjoin("~", pwd + home_len, '\0'));
	return (ms_strdup(pwd));
}

char	*get_prompt(t_shell *shell)
{
	char	*prompt;
	char	*pwd;
	char	*colored_pwd;
	char	*tmp;

	pwd = get_pwd(shell);
	if (pwd == NULL)
		pwd = ".";
	pwd = cut_home(shell, pwd);
	colored_pwd = ms_strjoin("\033[94m", pwd, '\0');
	free(pwd);
	tmp = colored_pwd;
	colored_pwd = ms_strjoin(colored_pwd, "\033[0m", '\0');
	free(tmp);
	tmp = ms_strjoin("\033[92mminishell\033[0m:", colored_pwd, '\0');
	free(colored_pwd);
	prompt = ms_strjoin(tmp, "$ ", '\0');
	free(tmp);
	return (prompt);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	*shell;
	char	*prompt;
	char	*input;

	(void) argc;
	(void) argv;
	shell = init_shell(envp);
	init_sighandler();
	while (true)
	{
		if (shell->last_input != NULL)
			free(shell->last_input);
		shell->last_input = NULL;
		prompt = get_prompt(shell);
		input = readline(prompt);
		free(prompt);
		if (input == NULL)
			ms_exit(EXEC_OK, NULL);
		add_history(input);
		shell->last_input = expand(shell, input);
		free(input);
		handle_cmd_input(shell);
	}
}
