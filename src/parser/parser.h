/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 05:07:26 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/16 05:20:33 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdbool.h>

/*
 - Parsed command
 */

typedef struct s_command
{
	char				**argv;
	char				*infile;
	char				*outfile;
	bool				is_append;
	bool				is_heredoc;
	struct s_command	*next;
}	t_command;

#endif
