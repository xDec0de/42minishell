/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:29:27 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/26 19:17:21 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_UTILS_H
# define STR_UTILS_H

# include "mem_utils.h"

int		ms_atoi(const char *str);

char	**ms_split(const char *s, char c);

char	*ms_strchr(const char *s, int c);

char	*ms_strdup(const char *str);

bool	ms_strequals(const char *str, const char *other);

int		ms_strindexof(const char *str, const char *substr, t_ulong start);

bool	ms_strisnumeric(const char *str, bool allow_spaces);

char	*ms_strjoin(char const *s1, char const *s2, char separator);

t_ulong	ms_strlcpy(char *dest, const char *src, t_ulong dstsize);

t_ulong	ms_strlen(const char *str);

char	*ms_strremchar(const char *str, const char ch);

char	*ms_strreplace(char *str, t_ulong from, t_ulong size,
			char *replacement);

char	*ms_substr(const char *str, unsigned int start, t_ulong len);

#endif
