/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:29:19 by rexposit          #+#    #+#             */
/*   Updated: 2025/07/28 12:13:22 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	write_heredoc_lines(int fd, char *delimiter)
{
	t_shell	*shell;
	char	*line;
	char	*expanded;

	shell = get_shell();
	while (true)
	{
		write(FD_OUT, "> ", 2);
		line = read_heredoc_line();
		if (line == NULL)
			break ;
		if (ms_strequals(line, delimiter))
		{
			free(line);
			break ;
		}
		expanded = expand(shell, line);
		write(fd, expanded, ms_strlen(expanded));
		write(fd, "\n", 1);
		free(line);
		free(expanded);
	}
}

static char	*generate_tempfile_path(void)
{
	int		tmp_num;
	int		fd;
	char	*tmp_num_str;
	char	*path;

	tmp_num = 0;
	while (true)
	{
		tmp_num_str = ms_itoa(tmp_num);
		path = ms_strjoin(HD_TEMP_PATH, tmp_num_str, '\0');
		free(tmp_num_str);
		fd = open(path, O_CREAT | O_EXCL | O_RDWR, PERM_URW_GR_OR);
		if (fd != -1)
			return (close(fd), path);
		free(path);
		tmp_num++;
	}
}

static bool	wait_heredoc_child(pid_t pid, char *path)
{
	t_shell	*shell;
	int		status;

	shell = get_shell();
	waitpid(pid, &status, 0);
	shell->heredoc_pid = 0;
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		shell->last_exit_code = HEREDOC_SIGINT_ERRN;
		unlink(path);
		free(path);
		return (false);
	}
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
	{
		shell->last_exit_code = WEXITSTATUS(status);
		unlink(path);
		free(path);
		return (false);
	}
	return (true);
}

static pid_t	fork_heredoc_process(char *delimiter, char *path, int fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		close(fd);
		free(path);
		return (-1);
	}
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		write_heredoc_lines(fd, delimiter);
		close(fd);
		exit(EXIT_SUCCESS);
	}
	return (pid);
}

char	*create_heredoc(char *delimiter)
{
	t_shell	*shell;
	char	*path;
	int		fd;
	pid_t	pid;

	shell = get_shell();
	path = generate_tempfile_path();
	fd = open(path, O_WRONLY | O_TRUNC);
	if (fd == -1)
		return (free(path), NULL);
	pid = fork_heredoc_process(delimiter, path, fd);
	if (pid == -1)
		return (NULL);
	shell->heredoc_pid = pid;
	if (!wait_heredoc_child(pid, path))
		return (NULL);
	close(fd);
	return (path);
}
