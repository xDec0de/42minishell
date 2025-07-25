/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 21:11:47 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/25 09:35:38 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "ms_types.h"

/**
 * @brief Gets the expanded value of a variable or special parameter.
 *
 * Example: If str="$HOME", returns "/home/user".
 *
 * @param shell The main minishell struct (used to access environment and $?).
 * @param str The original string containing the variable to expand.
 * @param from Index in str where the expansion starts (e.g., after '$').
 *
 * @return A newly allocated string with the expanded value,
 *         or NULL if the variable does not exist.
 */
char	*get_expanded_value(struct s_shell *shell, char *str, t_ulong from);

/**
 * @brief Calculates the size of the string after expansion.
 *
 * Example: "$HOME" → returns length of "/home/user".
 *
 * @param shell The main minishell struct (used to get environment values).
 * @param str The string to analyze (may contain multiple variables).
 *
 * @return The total size in characters after expansion.
 */
t_ulong	get_expanded_size(struct s_shell *shell, char *str);

/**
 * @brief Expands all variables and special parameters in a string.
 *
 * Example: "Hello $USER" → "Hello daniema3".
 *
 * @param shell The main minishell struct (for environment and $?).
 * @param str The original string to expand.
 *
 * @return A newly allocated string with all expansions applied.
 */
char	*expand(struct s_shell *shell, char *str);

#endif
