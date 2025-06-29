/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 10:50:33 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/30 01:19:12 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

struct	s_shell;
struct	s_token;

/*
 - Command handler
 */

void	handle_cmd_input(struct s_shell *shell);

/*
 - Command executor
 */

void	execute_cmd(struct s_shell *shell, struct s_token *token);

/*
 - External command executor
 */

void	execute_external(struct s_shell *shell, struct s_token *token);

# define EXECVE_ERRN -1

/*
 - Bultin command executor
 */

bool	is_state_builtin(char *cmd);

int		execute_state_builtins(struct s_shell *shell, struct s_token *token);

void	execute_fork_builtins(struct s_shell *shell, struct s_token *token);

/*
 - Builtins - cd
 */

int		bltn_cd(struct s_shell *shell, char **args);

/*
 - Builtins - echo
 */

void	bltn_echo(char **args);

/*
 - Builtins - env
 */

void	bltn_env(struct s_shell *shell);

int		print_env(struct s_shell *shell);

/*
 - Builtins - exit
 */

void	bltn_exit(char **args);

# define EXIT_NOT_NUMERIC_ERRN 2
# define EXIT_NOT_NUMERIC "bash: exit: %s: numeric argument required\n"

/*
 - Builtins - export
 */

int		bltn_export(struct s_shell *shell, char **args);

/*
 - Builtins - pwd
 */

void	bltn_pwd(void);

/*
 - Builtins - unset
 */

int		bltn_unset(struct s_shell *shell, char **args);

#endif
