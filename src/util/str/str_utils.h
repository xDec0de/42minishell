/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:29:27 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/22 13:41:10 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_UTILS_H
# define STR_UTILS_H

# include "mem_utils.h"

int		ms_atoi(const char *str);

char	**ms_split(const char *s, char c);

char	*ms_strchr(const char *s, int c);

char	*ms_strdup(const char *str);

bool	ms_strequals(char *str, char *other);

int		ms_strindexof(const char *str, const char *substr, size_t start);

bool	ms_strisnumeric(const char *str, bool allow_spaces);

size_t	ms_strlcpy(char *dest, const char *src, size_t dstsize);

size_t	ms_strlen(const char *str);

char	*ms_strreplace(char *str, size_t from, size_t size, char *replacement);

char	*ms_substr(const char *str, unsigned int start, size_t len);

#endif
