/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:29:19 by rexposit          #+#    #+#             */
/*   Updated: 2025/07/25 16:24:49 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static void	write_heredoc_lines(int fd, char *delimiter)
{
	char	*line;
	t_shell	*shell;

	shell = get_shell();
	while (true)
	{
		line = readline("> ");
		if (!line || ms_strequals(line, delimiter))
		{
			free(line);
			break ;
		}
		line = expand(shell, line);
		write(fd, line, ms_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
}

char	*create_heredoc(char *delimiter)
{
	char	*path;
	int		fd;
	t_shell	*shell;

	shell = get_shell();
	path = generate_tempfile_path();
	fd = open(path, O_WRONLY | O_TRUNC);
	if (fd == -1)
		return (free(path), NULL);
	shell->heredoc_pid = getpid();
	write_heredoc_lines(fd, delimiter);
	shell->heredoc_pid = 0;
	close(fd);
	if (shell->last_exit_code)
	{
		unlink(path);
		free(path);
		return (NULL);
	}
	return (path);
}
