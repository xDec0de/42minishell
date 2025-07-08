/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_strdup_vg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:19:22 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/08 13:32:15 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "str_utils.h"

int	main(void)
{
	ASSERT_NULL(ms_strdup(NULL));
	FREE_ASSERT_STR_EQUALS(ms_strdup("dup"), "dup");
	FREE_ASSERT_STR_EQUALS(ms_strdup("dup\0dup"), "dup");
}
