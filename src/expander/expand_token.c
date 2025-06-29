/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 22:11:47 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/29 22:14:33 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_token(t_shell *shell, t_token *token)
{
	char	*tmp;
	t_ulong	i;

	tmp = expand(shell, token->cmd);
	free(token->cmd);
	token->cmd = tmp;
	if (token->args == NULL)
		return ;
	i = 0;
	while (token->args[i] != NULL)
	{
		tmp = expand(shell, token->args[i]);
		free(token->args[i]);
		token->args[i] = tmp;
		i++;
	}
}
