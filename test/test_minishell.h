/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_minishell.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:53:14 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/12 15:52:30 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MINISHELL_H
# define TEST_MINISHELL_H

#include "unity.h"
#include "minishell.h"

# define _STR(x) #x
# define STR(x) _STR(x)

# define ASSERT_TRUE(expr, num) \
	TEST_ASSERT_TRUE_MESSAGE((expr), STR(num))

# define ASSERT_FALSE(expr, num) \
	TEST_ASSERT_FALSE_MESSAGE((expr), STR(num))

void	test_ms_isdigit(void);

#endif