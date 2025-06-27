/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:42:07 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/27 12:56:57 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem_utils.h"

static t_ulong	get_digits(long nb)
{
	t_ulong	digits;

	digits = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		digits++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		digits++;
	}
	return (digits);
}

char	*ms_itoa(int n)
{
	long	nb;
	t_ulong	digits;
	char	*res;

	nb = (long)n;
	digits = get_digits(nb);
	res = ms_calloc(digits + 2, sizeof(char));
	if (nb < 0)
	{
		res[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		res[0] = '0';
	while (nb > 0)
	{
		res[digits] = ('0' + (nb % 10));
		nb = nb / 10;
		digits--;
	}
	return (res);
}
