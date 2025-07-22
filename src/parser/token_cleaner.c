/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_cleaner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 22:20:07 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/18 22:41:58 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_token(t_token *token)
{
	if (token->cmd != NULL)
		free(token->cmd);
	ms_arrfree(token->args);
	if (token->infile != NULL)
		free(token->infile);
	if (token->outfile != NULL)
		free(token->outfile);
	free(token);
}

void	clean_tokens(t_token *tokens)
{
	t_token	*current;
	t_token	*to_delete;

	current = tokens;
       while (current != NULL && current->next != NULL)
       {
               if (current->type == T_REDIR_IN || current->type == T_REDIR_OUT
                       || current->type == T_REDIR_APPEND || current->type == T_HEREDOC)
               {
                       to_delete = current->next;
                       current->next = to_delete->next;
                       if (to_delete->infile != NULL)
                       {
                               if (current->infile != NULL)
                                       free(current->infile);
                               current->infile = to_delete->infile;
                               to_delete->infile = NULL;
                       }
                       if (to_delete->outfile != NULL)
                       {
                               if (current->outfile != NULL)
                                       free(current->outfile);
                               current->outfile = to_delete->outfile;
                               to_delete->outfile = NULL;
                       }
                       if (to_delete->type == T_PIPE)
                               current->type = T_PIPE;
                       free_token(to_delete);
               }
               else
                       current = current->next;
       }
}

void	free_token_list(t_token *head)
{
	t_token	*tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free_token(head);
		head = tmp;
	}
}
