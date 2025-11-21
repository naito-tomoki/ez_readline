/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ez_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaito <tnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:14:22 by tnaito            #+#    #+#             */
/*   Updated: 2025/11/21 18:24:47 by tnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EZ_READLINE_H
# define EZ_READLINE_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# include <stdbool.h>

# define HISTSIZE_DEFAULT 1000

typedef struct s_ezrl_conn
{
	const char	*conn_str;
	size_t		conn_str_len;
}	t_ezrl_conn;

typedef struct s_ezrl_history
{
	char					*recode;
	struct s_ezrl_history	*next;
}	t_ezrl_history;

typedef enum e_rl_type
{
	RL_NOSTOCK = 0,
	RL_INPUT,
	RL_AGAIN
}	t_rl_type;

typedef struct s_ezrl
{
	char			*input;
	int				history_size;
	t_ezrl_conn		conn_info;
	t_ezrl_history	*history;
	t_rl_type		input_type;
}	t_ezrl;

/* ez_readline.c */
t_ezrl	ezrl_init(void);
char	*ez_readline(const char *prompt, t_ezrl *rl_ptr);
void	ezrl_endall(t_ezrl *rl_ptr);

/* ez_readline_history.c */
bool	ezrl_add_history(t_ezrl *rl_ptr);
void	ezrl_set_history_stock(t_ezrl *history);
void	ezrl_destroy_history(t_ezrl *rl_ptr);
void	ezrl_rm_over_histsize(t_ezrl *rl_ptr);

/* ez_readline_option.c */
bool	ezrl_set_conn_str(const char *s, t_ezrl *rl_ptr);
bool	ezrl_set_histsize(int histsize, t_ezrl *rl_ptr);
int		ezrl_get_history_count(t_ezrl *rl_ptr);
bool	ezrl_rm_oldest_history(t_ezrl *rl_ptr);

#endif
