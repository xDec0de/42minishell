/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_substr_vg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:30:08 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/22 18:40:14 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "str_utils.h"

int	main(void)
{
	ASSERT_NULL(ms_substr(NULL, 0, 0), 1);
	FREE_ASSERT_STR_EQUALS(ms_substr("Hello, World!", 0, 5), "Hello", 1);
	FREE_ASSERT_STR_EQUALS(ms_substr("Hello, World!", 7, 42), "World!", 1);
	FREE_ASSERT_STR_EQUALS(ms_substr("Hello", 10, 5), "", 4);

}
