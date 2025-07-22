/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 10:50:33 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/21 21:15:43 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

struct	s_shell;
struct	s_token;

/** Exit code: Permission error. */
# define EC_NO_PERM 126

/** Exit code: Command not found. */
# define EC_CMD_NOT_FOUND 127

/*
 - Command handler
 */

void	handle_cmd_input(struct s_shell *shell);

/*
 - Redirections
 */

/**
 * File permission macro for Unix mode 0644:
 * - User (U): (R)ead + (W)rite -> 6
 * - Group (G): (R)ead only -> 4
 * - Others (O): (R)ead only -> 4
 * - Sections separated by underscores: URW_GR_OR
 */
# define PERM_URW_GR_OR 0644

bool	setup_redirections(struct s_token *token);
char *create_heredoc(char *delimiter);

/*
 - Command executor
 */

void	execute_tokens(struct s_shell *shell, struct s_token *token);

/*
 - External command executor
 */

void	execute_external(struct s_shell *shell, struct s_token *token);

/*
 - Path finder
*/

char	*get_cmd_from_path(struct s_shell *shell, char *cmd);

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

# define CD_NO_HOME "minishell: cd: HOME not set\n"
# define CD_CHDIR_ERR "minishell: cd: chdir error"
# define CD_PWD_ERR "minishell: cd: could not obtain pwd"

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

char	*get_pwd(struct s_shell *shell);

bool	set_pwd(struct s_shell *shell, char *pwd);

void	bltn_pwd(struct s_shell *shell);

/*
 - Builtins - unset
 */

int		bltn_unset(struct s_shell *shell, char **args);

#endif
