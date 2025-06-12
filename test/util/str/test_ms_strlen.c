/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 01:42:07 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/13 01:53:17 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_minishell.h"

void	test_ms_strlen(void)
{
	ASSERT_INT_EQUALS(ms_strlen(NULL), 0, 1);
	ASSERT_INT_EQUALS(ms_strlen(""), 0, 2);
	ASSERT_INT_EQUALS(ms_strlen("Hi"), 2, 3);
}
