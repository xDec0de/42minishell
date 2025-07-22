/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_exec.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:26:59 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/22 15:54:40 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_EXEC_H
# define TEST_EXEC_H

# include "minishell.h"
# include "ms_assertions.h"

# define LOG_PATH "./logs/test_exec"
# define MS_OUT LOG_PATH"/ms_out"
# define SH_OUT LOG_PATH"/sh_out"

t_shell *shell;

#define MS_INIT(argc, argv, env) do {\
	(void) (argc);\
	(void) (argv);\
	shell = init_shell((env));\
} while (0)

#define SILENCE_STDIO(code) do {\
	int __old_stdout__ = dup(STDOUT_FILENO);\
	int __old_stderr__ = dup(STDERR_FILENO);\
	int __null_fd__ = open("/dev/null", O_WRONLY);\
	if (__null_fd__ != -1) {\
		dup2(__null_fd__, STDOUT_FILENO);\
		dup2(__null_fd__, STDERR_FILENO);\
		close(__null_fd__);\
	}\
	code;\
	fflush(stdout); fflush(stderr);\
	dup2(__old_stdout__, STDOUT_FILENO);\
	dup2(__old_stderr__, STDERR_FILENO);\
	close(__old_stdout__);\
	close(__old_stderr__);\
} while (0)

#define MS_EXEC(cmd) do {\
	shell->last_input = (cmd);\
	SILENCE_STDIO(handle_cmd_input(shell));\
} while (0)

#define ASSERT_EXEC_EQUALS(cmd) do {\
	system("mkdir -p "LOG_PATH);\
	char *__aee_ms_cmd__ = ms_strjoin((cmd), "> "MS_OUT, ' ');\
	char *__aee_sh_cmd__ = ms_strjoin((cmd), "> "SH_OUT, ' ');\
	shell->last_input = __aee_ms_cmd__;\
	SILENCE_STDIO(handle_cmd_input(shell));\
	SILENCE_STDIO(system(__aee_sh_cmd__));\
	free(__aee_sh_cmd__);\
	ASSERT_FILE_EQUALS(MS_OUT, SH_OUT);\
} while (0)

#define ASSERT_FILE_EQUALS(ms_file, sh_file) do {\
	__TEST_NUMBER__++;\
	char __cmd_diff__[256];\
	snprintf(__cmd_diff__, sizeof(__cmd_diff__), "diff -q %s %s > /dev/null", (ms_file), (sh_file));\
	int __afe_diff__ = system(__cmd_diff__);\
	if (__afe_diff__ != 0) {\
		fprintf(stderr, "Different command output. Check "LOG_PATH);\
		system("cat "MS_OUT);\
		system("cat "SH_OUT);\
		exit(__TEST_NUMBER__);\
	}\
	unlink((ms_file));\
	unlink((sh_file));\
} while(0)

#endif
