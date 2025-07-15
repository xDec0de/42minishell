/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_splitter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:47:59 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/15 19:26:10 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ulong	get_token_count(const char *input)
{
	t_ulong	i;
	t_ulong	count;
	bool	in_word;
	char	quote;

	i = 0;
	count = 0;
	in_word = false;
	quote = '\0';
	while (input[i])
	{
		if (quote == '\0' && ms_isquote(input[i]))
			quote = input[i];
		else if (input[i] == quote)
			quote = '\0';
		if (quote == '\0' && input[i] == ' ')
			in_word = false;
		else if (!in_word && (quote != '\0' || input[i] != ' '))
		{
			in_word = true;
			count++;
		}
		i++;
	}
	return (count);
}

bool	is_sep(char ch)
{
	return (ch == '|' || ch == '<' || ch == '>');
}

static t_ulong	skip_spaces(const char *input, t_ulong i)
{
	while (input[i] != '\0' && ms_isspace(input[i]))
		i++;
	return (i);
}

static t_ulong	get_token_end(const char *input, t_ulong i)
{
	char	quote;

	if (is_sep(input[i]))
	{
		if ((input[i] == '>' && input[i + 1] == '>')
			|| (input[i] == '<' && input[i + 1] == '<'))
			return (i + 2);
		return (i + 1);
	}
	quote = '\0';
	while (input[i] != '\0')
	{
		if (quote == '\0' && ms_isquote(input[i]))
			quote = input[i];
		else if (quote != '\0' && input[i] == quote)
			quote = '\0';
		else if (quote == '\0' && (ms_isspace(input[i]) || is_sep(input[i])))
			break ;
		i++;
	}
	return (i);
}

char	**to_token_array(const char *input)
{
	t_ulong	i;
	t_ulong	j;
	t_ulong	end;
	char	**tokens;
	char	*tmp;

	tokens = ms_malloc(sizeof(char *) * (get_token_count(input) + 1));
	i = 0;
	j = 0;
	while (input[i] != '\0')
	{
		i = skip_spaces(input, i);
		if (!input[i])
			break ;
		end = get_token_end(input, i);
		tmp = ms_substr(input, i, end - i);
		tokens[j] = ms_strremchar(tmp, '"');
		free(tmp);
		i = end;
		j++;
	}
	tokens[j] = NULL;
	return (tokens);
}
