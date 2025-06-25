/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_splitter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:47:59 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/25 16:04:51 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_types.h"
#include "str_utils.h"
#include "char_utils.h"

t_ulong	get_token_count(const char *s)
{
	t_ulong	i;
	t_ulong	count;
	bool	in_word;
	char	quote;

	i = 0;
	count = 0;
	in_word = false;
	quote = '\0';
	while (s[i])
	{
		if (quote == '\0' && ms_isquote(s[i]))
			quote = s[i];
		else if (s[i] == quote)
			quote = '\0';
		if (quote == '\0' && s[i] == ' ')
			in_word = false;
		else if (!in_word && (quote != '\0' || s[i] != ' '))
		{
			in_word = true;
			count++;
		}
		i++;
	}
	return (count);
}

bool	is_sep(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

static t_ulong	skip_spaces(const char *s, t_ulong i)
{
	while (s[i] != '\0' && ms_isspace(s[i]))
		i++;
	return (i);
}

static t_ulong	get_token_end(const char *s, t_ulong i)
{
	char	quote;

	if (is_sep(s[i]))
		return (i + 1);
	quote = 0;
	while (s[i] != '\0')
	{
		if (!quote && ms_isquote(s[i]))
			quote = s[i];
		else if (quote && s[i] == quote)
			quote = 0;
		else if (!quote && (ms_isspace(s[i]) || is_sep(s[i])))
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

	tokens = ms_malloc(sizeof(char *) * (get_token_count(input) + 1));
	i = 0;
	j = 0;
	while (input[i] != '\0')
	{
		i = skip_spaces(input, i);
		if (!input[i])
			break ;
		end = get_token_end(input, i);
		tokens[j++] = ms_substr(input, i, end - i);
		i = end;
	}
	tokens[j] = NULL;
	return (tokens);
}
