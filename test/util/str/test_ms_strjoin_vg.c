/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_strjoin_vg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 01:42:07 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/08 13:29:56 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "str_utils.h"

int	main(void)
{
	FREE_ASSERT_STR_EQUALS(ms_strjoin("Hello ", "world", '\0'), "Hello world");
	FREE_ASSERT_STR_EQUALS(ms_strjoin("Hello", "world", ' '), "Hello world");
}
