/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:52:17 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/12 13:55:29 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_minishell.h"

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ms_isdigit);
	return UNITY_END();
}

void setUp(void) {}
void tearDown(void) {}

