/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 05:07:26 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/29 22:09:45 by daniema3         ###   ########.fr       */
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
	T_END,
	T_PIPE,
	T_REDIR_IN,
	T_REDIR_OUT,
	T_REDIR_APPEND,
	T_HEREDOC
}	t_token_type;

typedef struct s_token
{
	char			*cmd;
	char			**args;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

/*
 - Input splitter
 */

char			**to_token_array(const char *input);

/*
 - Input validator
 */

bool			check_quotes(const char *line);

/*
 - Tokenizer
 */

t_ulong			get_token_count(const char *input);
t_token			*tokenize(char **tokens);
void			free_token_list(t_token *head);

#endif
