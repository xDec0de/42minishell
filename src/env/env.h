/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:56:25 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/21 01:16:29 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <stdbool.h>

struct	s_shell;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}			t_env;

bool	env_export(struct s_shell *shell, char *env);

void	env_free(struct s_shell *shell);

t_env	*env_get(struct s_shell *shell, char *key);

void	env_init(struct s_shell *shell, char **env);

bool	env_unset(struct s_shell *shell, char *key);

#endif
