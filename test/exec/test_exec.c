/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:26:41 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/22 15:23:22 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_exec.h"

int	main(int argc, char **argv, char **env)
{
	MS_INIT(argc, argv, env);
	ASSERT_EXEC_EQUALS("echo Hello world");
	ASSERT_EXEC_EQUALS("ls");
	ASSERT_EXEC_EQUALS("echo pipe | cat -e");
	ASSERT_EXEC_EQUALS("cat < README.md | grep stdlib.h");
}
