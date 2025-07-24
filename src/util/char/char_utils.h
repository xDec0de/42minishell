/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:33:41 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/24 18:16:06 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_UTILS_H
# define CHAR_UTILS_H

/* bool type */
# include <stdbool.h>

/**
 * @brief Checks if a character is a digit (0-9).
 *
 * @param ch The character to check.
 *
 * @return true if the character is a digit, false otherwise.
 */
bool	ms_isdigit(char ch);

/**
 * @brief Checks if `ch` is a valid character for an environment
 * key, following this pattern: [a-zA-Z0-9_], so alphanumeric
 * characters and the '_' character.
 * 
 * @param ch The character to check
 * 
 * @return `true` if the character is allowed as an environment
 * key character, `false` otherwise.
 */
bool	ms_isenvkeychar(const char ch);

/**
 * @brief Checks if a character is a quote (' or ").
 *
 * @param c The character to check.
 *
 * @return true if the character is a single or double quote, false otherwise.
 */
bool	ms_isquote(char c);

/**
 * @brief Checks if a character is considered whitespace.
 *
 * Recognized whitespaces: space, tab, newline, carriage return, etc.
 *
 * @param ch The character to check.
 *
 * @return true if the character is a whitespace, false otherwise.
 */
bool	ms_isspace(char ch);

/**
 * @brief Checks if a character is a minishell special character.
 *
 * Special characters: `|`, `<`, `>`.
 *
 * @param ch The character to check.
 *
 * @return true if the character is special, false otherwise.
 */
bool	ms_isspecial(char ch);

#endif
