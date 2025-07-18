/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 05:07:26 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/18 19:46:03 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "ms_types.h"

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
	char			*infile;
	char			*outfile;
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

bool			check_special_char_count(const char *input);

# define SCC_ERR "minishell: Syntax error: Unexpected special character.\n"

bool			check_quotes(const char *line);

bool			validate_input(const char *line);

/*
 - Tokenizer
 */

t_ulong			get_token_count(const char *input);
t_token			*tokenize(char **tokens);
void			free_token_list(t_token *head);

#endif
