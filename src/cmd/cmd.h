/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 10:50:33 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/29 17:37:06 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

struct	s_shell;

/*
 - Command functions
 */

void	parse_cmd_input(struct s_shell *shell);

/*
 - External command executor
 */

void	execute_external(struct s_shell *shell, char *cmd, char **args);

# define EXECVE_ERRN -1

/*
 - Builtins
 */

void	bltn_cd(struct s_shell *shell, char **args);

void	bltn_echo(char **args);

void	bltn_env(struct s_shell *shell);

void	bltn_exit(char **args);

# define EXIT_NOT_NUMERIC_ERRN 2
# define EXIT_NOT_NUMERIC "bash: exit: %s: numeric argument required\n"

void	bltn_export(struct s_shell *shell, char **args);

void	bltn_pwd(void);

void	bltn_unset(struct s_shell *shell, char **args);

#endif
