/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:25:21 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/25 18:50:24 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_types.h"
#include "char_utils.h"
#include "parser.h"
#include "str_utils.h"
#include <stdlib.h>

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
	return (T_WORD);
}

t_token	*add_token(t_token *head, char *value, t_token_type type)
{
	t_token	*tmp;
	t_token	*new;

	new = ms_malloc(sizeof(t_token));
	new->value = value;
	new->type = type;
	new->next = NULL;
	tmp = head;
	if (head == NULL)
		return (new);
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (head);
}

void	tokenize_one(t_token **head, char *token, char **value)
{
	char			*tmp;
	t_token_type	type;

	type = get_token_type(token);
	if (type != T_WORD)
	{
		*head = add_token(*head, *value, type);
		*value = NULL;
	}
	else
	{
		if (*value == NULL)
			*value = ms_strdup(token);
		else
		{
			tmp = *value;
			*value = ms_strjoin(*value, token, ' ');
			free(tmp);
		}
	}
}

t_token	*tokenize(char **tokens)
{
	t_ulong			i;
	t_token			*head;
	char			*value;

	i = 0;
	head = NULL;
	value = NULL;
	while (tokens[i] != NULL)
	{
		tokenize_one(&head, tokens[i], &value);
		i++;
	}
	if (value != NULL)
		add_token(head, value, T_WORD);
	return (head);
}

void	free_token_list(t_token *head)
{
	t_token	*tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head->value);
		free(head);
		head = tmp;
	}
}
