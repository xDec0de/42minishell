/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:26:41 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/22 16:55:50 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_exec.h"

static char	*get_shlvl(char **env)
{
	for (int i = 0; env[i]; i++)
		if (strncmp(env[i], "SHLVL=", 6) == 0)
			return (ms_strjoin("export SHLVL=", ms_itoa(ms_atoi(env[i] + 6)), '\0'));
	return (NULL);
}

int	main(int argc, char **argv, char **env)
{
	char	*shlvl = get_shlvl(env);

	MS_INIT(argc, argv, env);
	// Fix SHLVL
	if (shlvl != NULL)
	{
		MS_EXEC(shlvl);
		free(shlvl);
	}
	else
		MS_EXEC("unset SHLVL");
	// Non-state builtins
	ASSERT_EXEC_EQUALS("echo Hello world");
	ASSERT_EXEC_EQUALS("env");
	ASSERT_EXEC_EQUALS("pwd");
	// External commands
	ASSERT_EXEC_EQUALS("ls");
	ASSERT_EXEC_EQUALS("echo pipe | cat -e");
	ASSERT_EXEC_EQUALS("cat < README.md | grep stdlib.h");
	// Heredoc
	ASSERT_HEREDOC("cat << EOF > here_doc\nHello world\nEOF", "Hello world");
	// Some random command
	ASSERT_EXEC_EXIT_CODE("unknown_random_command", EC_CMD_NOT_FOUND);
	// Unset PATH
	MS_EXEC("unset PATH");
	ASSERT_EXEC_EXIT_CODE("ls", EC_CMD_NOT_FOUND);
}
