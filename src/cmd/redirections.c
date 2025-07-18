/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:36:43 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/18 19:58:03 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	open_input(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd == -1 || dup2(fd, FD_IN) == -1)
		return (false);
	close(fd);
	return (0);
}

bool	open_output(char *outfile, t_token *token)
{
	int	fd;

	if (token->type == T_REDIR_APPEND)
		fd = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1 || dup2(fd, FD_OUT) == -1)
		return (false);
	close(fd);
	return (true);
}

bool	setup_redirections(t_token *token)
{
	if (token->infile && !open_input(token->infile))
		return (false);
	if (token->outfile && !open_output(token->outfile, token))
		return (false);
	return (true);
}
