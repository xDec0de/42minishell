/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 21:11:47 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/27 15:04:56 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "ms_types.h"

char	*get_expanded_value(struct s_shell *shell, char *str, t_ulong from);

t_ulong	get_expanded_size(struct s_shell *shell, char *str);

#endif
