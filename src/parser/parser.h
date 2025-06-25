/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 05:07:26 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/25 13:32:53 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "ms_types.h"

/*
 - Parsed command
 */

typedef struct s_command
{
	char				**argv;
	char				*infile;
	char				*outfile;
	bool				is_append;
	bool				is_heredoc;
	struct s_command	*next;
}	t_command;

/*
 - Tokenizer
 */

typedef enum e_token_type
{
	T_PIPE,
	T_REDIR_IN,
	T_REDIR_OUT,
	T_REDIR_APPEND,
	T_HEREDOC
}	t_token_type;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

/*
 - Input validator
 */

bool	check_quotes(const char *line);

/*
 - Tokenizer
 */

t_ulong	get_token_count(const char *input);

#endif
