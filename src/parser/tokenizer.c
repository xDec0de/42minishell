/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:25:21 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/22 13:51:28 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
