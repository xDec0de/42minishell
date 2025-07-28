/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 10:50:33 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/28 12:10:18 by daniema3         ###   ########.fr       */
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

/**
 * @brief Main handler for processing and executing command input.
 *
 * @param shell The main minishell struct containing environment and state.
 */
void	handle_cmd_input(struct s_shell *shell);

/**
 * Path used to store temporary heredoc files.
 */
# define HD_TEMP_PATH "/tmp/ms_hd_"

/**
 * File permission macro for Unix mode 0644:
 * - User (U): (R)ead + (W)rite -> 6
 * - Group (G): (R)ead only -> 4
 * - Others (O): (R)ead only -> 4
 * - Sections separated by underscores: URW_GR_OR
 */
# define PERM_URW_GR_OR 0644

/**
 * @brief Sets up redirections (input, output, append, heredoc) for a command.
 *
 * @param token The token representing the current command and its redirections.
 *
 * @return true if all redirections were successfully set, false otherwise.
 */
bool	setup_redirections(struct s_token *token);

# define HEREDOC_SIGINT_ERRN 130

char	*read_heredoc_line(void);

/**
 * @brief Creates and writes a heredoc temporary file.
 *
 * @param delimiter The heredoc delimiter string.
 *
 * @return The path to the created heredoc file, or NULL on failure.
 */
char	*create_heredoc(char *delimiter);

/**
 * @brief Executes a sequence of parsed tokens, handling pipes and redirections.
 *
 * @param shell The main minishell struct.
 * @param token The first token in the command sequence.
 */
void	execute_tokens(struct s_shell *shell, struct s_token *token);

/**
 * @brief Executes an external command (using execve).
 *
 * @param shell The main minishell struct.
 * @param token The token representing the command to execute.
 */
void	execute_external(struct s_shell *shell, struct s_token *token);

/**
 * @brief Searches for the executable path of a given command.
 *
 * @param shell The main minishell struct (used for environment PATH).
 * @param cmd The command name to locate.
 *
 * @return The absolute path to the command, or NULL if not found.
 */
char	*get_cmd_from_path(struct s_shell *shell, char *cmd);

/**
 * Error code returned when execve fails unexpectedly.
 */
# define EXECVE_ERRN -1

/**
 * @brief Checks if a command is a state builtin (cd, export, unset, exit).
 *
 * @param cmd The command name to check.
 *
 * @return true if it is a state builtin, false otherwise.
 */
bool	is_state_builtin(char *cmd);

/**
 * @brief Executes state builtins directly in the parent process.
 *
 * @param shell The main minishell struct.
 * @param token The token representing the builtin command.
 *
 * @return Exit code of the executed builtin.
 */
int		execute_state_builtins(struct s_shell *shell, struct s_token *token);

/**
 * @brief Executes builtins that require forking (echo, env, pwd).
 *
 * @param shell The main minishell struct.
 * @param token The token representing the builtin command.
 */
void	execute_fork_builtins(struct s_shell *shell, struct s_token *token);

/**
 * @brief Changes the current working directory.
 *
 * @param shell The main minishell struct (updates PWD and OLDPWD).
 * @param args Arguments passed to the cd command.
 *
 * @return 0 on success, non-zero on failure.
 */
int		bltn_cd(struct s_shell *shell, char **args);

# define CD_NO_HOME "minishell: cd: HOME not set\n"
# define CD_CHDIR_ERR "minishell: cd: chdir error"
# define CD_PWD_ERR "minishell: cd: could not obtain pwd"

/**
 * @brief Prints arguments to the standard output.
 *
 * @param args Arguments to print, starting with argv[1].
 */
void	bltn_echo(char **args);

/**
 * @brief Prints the current environment variables.
 *
 * @param shell The main minishell struct containing the environment.
 */
void	bltn_env(struct s_shell *shell);

/**
 * @brief Prints all environment variables (helper for export).
 *
 * @param shell The main minishell struct.
 *
 * @return 0 on success, non-zero on failure.
 */
int		print_env(struct s_shell *shell);

/**
 * @brief Exits the shell, optionally with a given exit code.
 *
 * @param args Arguments, where args[1] may contain the exit code.
 */
void	bltn_exit(char **args);

# define EXIT_NOT_NUMERIC_ERRN 2
# define EXIT_NOT_NUMERIC "bash: exit: %s: numeric argument required\n"

/**
 * @brief Adds or updates environment variables.
 *
 * @param shell The main minishell struct.
 * @param args Arguments to export (key=value).
 *
 * @return 0 on success, non-zero on failure.
 */
int		bltn_export(struct s_shell *shell, char **args);

/**
 * @brief Retrieves the current working directory (PWD).
 *
 * @param shell The main minishell struct.
 *
 * @return A dynamically allocated string with the current directory.
 */
char	*get_pwd(struct s_shell *shell);

/**
 * @brief Updates the PWD environment variable.
 *
 * @param shell The main minishell struct.
 * @param pwd The new working directory to set.
 *
 * @return true on success, false on failure.
 */
bool	set_pwd(struct s_shell *shell, char *pwd);

/**
 * @brief Prints the current working directory.
 *
 * @param shell The main minishell struct.
 */
void	bltn_pwd(struct s_shell *shell);

/**
 * @brief Removes environment variables.
 *
 * @param shell The main minishell struct.
 * @param args List of variables to unset.
 *
 * @return 0 on success, non-zero on failure.
 */
int		bltn_unset(struct s_shell *shell, char **args);

#endif
