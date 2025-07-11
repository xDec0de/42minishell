/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:33:41 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/04 16:47:22 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_UTILS_H
# define CHAR_UTILS_H

/* bool type */
# include <stdbool.h>

bool	ms_isdigit(char ch);

bool	ms_isquote(char c);

bool	ms_isspace(char ch);

bool	ms_isspecial(char ch);

#endif
