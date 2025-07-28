/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:47:21 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/28 12:21:15 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_heredoc_line(void)
{
	char	buf[1];
	t_ulong	bytes;
	char	*line;
	char	*temp;

	line = ms_malloc(1);
	line[0] = '\0';
	while (true)
	{
		bytes = read(FD_IN, buf, 1);
		if (bytes <= 0 || buf[0] == '\n')
			break ;
		temp = line;
		line = ms_strjoin(temp, (char []){buf[0], '\0'}, '\0');
		free(temp);
	}
	if (bytes == 0)
		write(FD_OUT, "\n", 1);
	if (bytes <= 0 && line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
