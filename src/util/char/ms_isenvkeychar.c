/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_isenvkeychar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 18:07:18 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/24 19:20:55 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_types.h"
#include "char_utils.h"

bool	ms_isenvkeychar(const char ch)
{
	return ((ch >= 'A' && ch <= 'Z')
		|| (ch >= 'a' && ch <= 'z')
		|| ms_isdigit(ch) || ch == '_');
}
