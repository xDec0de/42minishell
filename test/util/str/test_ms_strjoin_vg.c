/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_strjoin_vg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 01:42:07 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/25 17:56:24 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "str_utils.h"

int	main(void)
{
	FREE_ASSERT_STR_EQUALS(ms_strjoin("Hello ", "world", '\0'), "Hello world", 1);
	FREE_ASSERT_STR_EQUALS(ms_strjoin("Hello", "world", ' '), "Hello world", 2);
}
