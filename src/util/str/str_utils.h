/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:29:27 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/25 12:27:44 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_UTILS_H
# define STR_UTILS_H

# include "mem_utils.h"

/**
 * @brief Converts a string to an integer.
 *
 * Similar to standard atoi, handles optional + or - signs.
 *
 * @param str The string to convert.
 *
 * @return The integer representation of the string.
 */
int		ms_atoi(const char *str);

/**
 * @brief Converts an integer to a string.
 *
 * @param n The integer to convert.
 *
 * @return A newly allocated string representing the number.
 */
char	*ms_itoa(int n);

/**
 * @brief Splits a string into an array of substrings based on a delimiter.
 *
 * @param s The original string to split.
 * @param c The delimiter character.
 *
 * @return A NULL-terminated array of strings, or NULL on failure.
 */
char	**ms_split(const char *s, char c);

/**
 * @brief Finds the first occurrence of a character in a string.
 *
 * @param s The string to search.
 * @param c The character to find.
 *
 * @return A pointer to the first occurrence, or NULL if not found.
 */
char	*ms_strchr(const char *s, int c);

/**
 * @brief Duplicates a string by allocating new memory.
 *
 * @param str The string to duplicate.
 *
 * @return A newly allocated copy of the string.
 */
char	*ms_strdup(const char *str);

/**
 * @brief Compares two strings for equality.
 *
 * @param str First string.
 * @param other Second string.
 *
 * @return true if both strings are identical, false otherwise.
 */
bool	ms_strequals(const char *str, const char *other);

/**
 * @brief Finds the index of a substring in a string starting from an index.
 *
 * @param str The string to search.
 * @param substr The substring to find.
 * @param start Starting index for the search.
 *
 * @return The index of the first occurrence, or -1 if not found.
 */
int		ms_strindexof(const char *str, const char *substr, t_ulong start);

/**
 * @brief Checks if a string is numeric (optionally allowing spaces).
 *
 * @param str The string to check.
 * @param allow_spaces Whether spaces are allowed before/after the number.
 *
 * @return true if the string represents a valid number, false otherwise.
 */
bool	ms_strisnumeric(const char *str, bool allow_spaces);

/**
 * @brief Joins two strings with an optional separator character.
 *
 * @param s1 First string.
 * @param s2 Second string.
 * @param separator Character to insert between the two strings
 *                  (use '\0' for no separator).
 *
 * @return A newly allocated joined string.
 */
char	*ms_strjoin(char const *s1, char const *s2, char separator);

/**
 * @brief Copies a string into a destination buffer (size-limited).
 *
 * Works similarly to standard strlcpy.
 *
 * @param dest Destination buffer.
 * @param src Source string.
 * @param dstsize Total size of the destination buffer.
 *
 * @return The total length of src.
 */
t_ulong	ms_strlcpy(char *dest, const char *src, t_ulong dstsize);

/**
 * @brief Gets the length of a string.
 *
 * @param str The string to measure.
 *
 * @return The number of characters in the string.
 */
t_ulong	ms_strlen(const char *str);

int		ms_strncmp(const char *s1, const char *s2, t_ulong n);

/**
 * @brief Removes all occurrences of a character from a string.
 *
 * @param str The original string.
 * @param ch The character to remove.
 *
 * @return A newly allocated string without the specified character.
 */
char	*ms_strremchar(const char *str, const char ch);

/**
 * @brief Replaces a portion of a string with another string.
 *
 * @param str The original string.
 * @param from Starting index of the replacement.
 * @param size Number of characters to replace.
 * @param replacement The string to insert in place.
 *
 * @return A newly allocated modified string.
 */
char	*ms_strreplace(char *str, t_ulong from, t_ulong size,
			char *replacement);

/**
 * @brief Extracts a substring from a string.
 *
 * @param str The original string.
 * @param start The starting index of the substring.
 * @param len The length of the substring.
 *
 * @return A newly allocated substring.
 */
char	*ms_substr(const char *str, unsigned int start, t_ulong len);

#endif
