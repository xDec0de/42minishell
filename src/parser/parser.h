/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 05:07:26 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/24 17:26:24 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "ms_types.h"

/**
 * @brief Represents the type of a token (command separator or redirection).
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

/**
 * @brief Represents a parsed token (command or operator).
 *
 * - cmd: The command name (NULL for pure operators).
 * - args: Array of arguments (NULL-terminated).
 * - infile: File for input redirection, NULL if none.
 * - outfile: File for output redirection, NULL if none.
 * - type: Type of the token (T_PIPE, T_REDIR_OUT, etc.).
 * - next: Pointer to the next token in the list.
 */
typedef struct s_token
{
	char			*cmd;
	char			**args;
	char			*infile;
	char			*outfile;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

/**
 * @brief Splits a raw input line into an array of string tokens.
 *
 * @param input The raw input line (e.g., "ls -l | grep .c").
 *
 * @return A NULL-terminated array of token strings.
 */
char			**to_token_array(const char *input);

/**
 * @brief Checks for invalid consecutive special characters (pipes or redirects).
 *
 * @param input The raw input line to validate.
 *
 * @return true if the input is valid, false otherwise.
 */
bool			check_special_char_count(const char *input);

# define SCC_ERR "minishell: Syntax error: Unexpected special character.\n"

/**
 * @brief Verifies if all quotes are properly closed.
 *
 * @param line The input line to validate.
 *
 * @return true if quotes are balanced, false otherwise.
 */
bool			check_quotes(const char *line);

/**
 * @brief Validates the entire input line (quotes, syntax, etc.).
 *
 * @param line The input line to validate.
 *
 * @return true if the input is valid, false otherwise.
 */
bool			validate_input(const char *line);

/**
 * @brief Frees all allocated memory inside a token list
 *        (but not the list itself).
 *
 * @param tokens The token list to clean.
 */
void			clean_tokens(t_token *tokens);

/**
 * @brief Counts how many tokens are present in the input string.
 *
 * @param input The raw input line.
 *
 * @return The number of tokens.
 */
t_ulong			get_token_count(const char *input);

/**
 * @brief Converts an array of string tokens into a linked list of t_token.
 *
 * @param tokens The NULL-terminated array of token strings.
 *
 * @return A linked list of parsed tokens.
 */
t_token			*tokenize(char **tokens);

/**
 * @brief Frees a linked list of tokens completely.
 *
 * @param head The first token in the list.
 */
void			free_token_list(t_token *head);

#endif
