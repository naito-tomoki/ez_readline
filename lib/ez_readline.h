/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ez_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaito <tnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:14:22 by tnaito            #+#    #+#             */
/*   Updated: 2025/10/22 19:10:45 by tnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EZ_READLINE_H
# define EZ_READLINE_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include <stdbool.h>

typedef struct s_ezrl_stock
{
	char 				*history;
	struct s_ezrl_stock	*next;
}	t_ezrl_stock;

typedef struct s_ezrl
{
	char			*input;
	t_ezrl_stock	stock;
	bool			is_add_history;
}	t_ezrl;

bool	ezrl_init_t_ezrl(t_ezrl **rl_ptr);
char	*ez_readline(const char *prompt, t_ezrl **rl_ptr);

#endif
