/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ez_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaito <tnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:14:22 by tnaito            #+#    #+#             */
/*   Updated: 2025/10/23 10:19:34 by tnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EZ_READLINE_H
# define EZ_READLINE_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# include <stdbool.h>

typedef struct s_ezrl_stock
{
	char				*history;
	struct s_ezrl_stock	*next;
}	t_ezrl_stock;

typedef enum e_rl_type
{
	RL_NOSTOCK = 0,
	RL_INPUT,
	RL_AGAIN
}	t_rl_type;

typedef struct s_ezrl
{
	char			*input;
	t_ezrl_stock	*history;
	t_rl_type		input_type;
}	t_ezrl;

t_ezrl	ezrl_init(void);
char	*ez_readline(const char *prompt, t_ezrl *rl_ptr);
bool	ezrl_add_history(t_ezrl *rl_ptr);
void	ezrl_set_history_stock(t_ezrl_stock *history);
void	ezrl_destroy_history(t_ezrl *rl_ptr);

#endif
