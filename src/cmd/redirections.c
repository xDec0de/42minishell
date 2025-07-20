/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:36:43 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/20 17:18:59 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	open_input(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd == -1)
	{
		ms_print(FD_ERR, "minishell: cannot open '");
		ms_print(FD_ERR, infile);
		ms_print(FD_ERR, "': ");
		ms_print(FD_ERR, strerror(errno));
		ms_print(FD_ERR, "\n");
		return (false);
	}
	if (dup2(fd, FD_IN) == -1)
	{
		ms_print(FD_ERR, "minishell: dup2 failed on infile '");
		ms_print(FD_ERR, infile);
		ms_print(FD_ERR, "': ");
		ms_print(FD_ERR, strerror(errno));
		ms_print(FD_ERR, "\n");
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}

bool	open_output(char *outfile, t_token *token)
{
	int	fd;

	if (token->type == T_REDIR_APPEND)
		fd = open(outfile, O_WRONLY | O_CREAT | O_APPEND, PERM_URW_GR_OR);
	else
		fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, PERM_URW_GR_OR);
	if (fd == -1 || dup2(fd, FD_OUT) == -1)
		return (false);
	close(fd);
	return (true);
}

bool	setup_redirections(t_token *token)
{
	if (token->infile != NULL && !open_input(token->infile))
		return (false);
	if (token->outfile != NULL && !open_output(token->outfile, token))
		return (false);
	return (true);
}
