/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 01:42:07 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/14 21:00:57 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_minishell.h"

int	main(void)
{
	ASSERT_ULONG_EQUALS(ms_strlen(NULL), 0L, 1);
	ASSERT_ULONG_EQUALS(ms_strlen(""), 0L, 2);
	ASSERT_ULONG_EQUALS(ms_strlen("Hi"), 2L, 3);
}
