/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:11:24 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/24 19:06:49 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_utils.h"

void	ms_print(const int fd, const char *msg)
{
	if (msg == NULL)
		write(fd, "(null)", 6);
	else
		write(fd, msg, ms_strlen(msg));
}
