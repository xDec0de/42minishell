/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:25:21 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/25 13:55:26 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_types.h"
#include "char_utils.h"
#include "parser.h"
#include "str_utils.h"

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
