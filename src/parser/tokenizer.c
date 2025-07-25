/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:25:21 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/25 13:05:37 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token_type	get_token_type(const char *s)
{
	if (ms_strequals(s, "|"))
		return (T_PIPE);
	if (ms_strequals(s, "<"))
		return (T_REDIR_IN);
	if (ms_strequals(s, ">"))
		return (T_REDIR_OUT);
	if (ms_strequals(s, ">>"))
		return (T_REDIR_APPEND);
	if (ms_strequals(s, "<<"))
		return (T_HEREDOC);
	return (T_END);
}

t_token	*add_token(t_token *head, char ***value, t_token_type type)
{
	t_token	*tmp;
	t_token	*new;

	new = ms_malloc(sizeof(t_token));
	if (*value == NULL)
		new->cmd = NULL;
	else
		new->cmd = ms_strdup(*value[0]);
	new->args = ms_arrdup(1, *value);
	new->type = type;
	new->next = NULL;
	new->infile = NULL;
	new->outfile = NULL;
	ms_arrfree(*value);
	*value = NULL;
	tmp = head;
	if (head == NULL)
		return (new);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (head);
}

static char	*remove_quotes(char *arg)
{
	char	*clean;

	clean = ms_strremchar(arg, '"');
	return (clean);
}

void	tokenize_one(t_token **head, char *token, char ***value)
{
	char			**tmp;
	t_token_type	type;
	char			*arg;

	type = get_token_type(token);
	if (type != T_END)
		*head = add_token(*head, value, type);
	else
	{
		arg = remove_quotes(token);
		if (*value == NULL)
			*value = ms_arradd(*value, arg);
		else
		{
			tmp = *value;
			*value = ms_arradd(*value, arg);
			free(tmp);
		}
	}
}

t_token	*tokenize(char **tokens)
{
	t_ulong			i;
	t_token			*head;
	char			**value;

	i = 0;
	head = NULL;
	value = NULL;
	while (tokens[i] != NULL)
	{
		tokenize_one(&head, tokens[i], &value);
		i++;
	}
	if (value != NULL)
		head = add_token(head, &value, T_END);
	return (head);
}
