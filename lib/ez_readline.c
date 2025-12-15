/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ez_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaito <tnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:13:50 by tnaito            #+#    #+#             */
/*   Updated: 2025/12/16 02:55:21 by tnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ez_readline.h"
#include "rl_wrapper.h"
#include "libft.h"
#include <stdlib.h>

t_ezrl	ezrl_init(void)
{
	t_ezrl	rl;

	rl_attempted_completion_function = rlwp_completion_setting;
	rl.total_lines = 0;
	rl.input = NULL;
	rl.history = NULL;
	rl.input_type = RL_NOSTOCK;
	ezrl_set_histsize(HISTSIZE_DEFAULT, &rl);
	ezrl_set_conn_str(" ", &rl);
	return (rl);
}

static t_rl_type	ezrl_add_input_type(t_rl_type input_type)
{
	if (input_type == RL_NOSTOCK)
		return (RL_INPUT);
	return (RL_AGAIN);
}

static bool	ezrl_conn_input(char *line, t_ezrl rl_ptr[static 1])
{
	char	*tmp;
	size_t	prev_len;
	size_t	line_len;

	if (rl_ptr->input_type == RL_NOSTOCK)
	{
		rl_ptr->input = line;
		return (true);
	}
	prev_len = ft_strlen(rl_ptr->input);
	line_len = ft_strlen(line);
	tmp = malloc(prev_len + line_len + rl_ptr->conn_info.conn_str_len + 1);
	if (tmp == NULL)
		return (false);
	ft_memmove(tmp, rl_ptr->input, prev_len);
	ft_memmove(tmp + prev_len, rl_ptr->conn_info.conn_str,
		rl_ptr->conn_info.conn_str_len);
	ft_memmove(tmp + prev_len + rl_ptr->conn_info.conn_str_len, line, line_len);
	tmp[prev_len + line_len + rl_ptr->conn_info.conn_str_len] = '\0';
	free(line);
	free(rl_ptr->input);
	rl_ptr->input = tmp;
	return (true);
}

const char	*ez_readline(const char *prompt, t_ezrl *rl_ptr)
{
	char	*line;
	size_t	len;

	if (rl_ptr == NULL)
		return (NULL);
	line = readline(prompt);
	if (line == NULL)
		return (NULL);
	len = ft_strlen(line);
	if (rlwp_is_safe_add_history(line) == false)
	{
		free(line);
		return ("");
	}
	if (ezrl_conn_input(line, rl_ptr) == false)
	{
		free(line);
		return (NULL);
	}
	if (rl_ptr->input_type != RL_NOSTOCK)
		ezrl_set_history_stock(rl_ptr);
	add_history(rl_ptr->input);
	rl_ptr->input_type = ezrl_add_input_type(rl_ptr->input_type);
	return (rl_ptr->input + ft_strlen(rl_ptr->input) - len);
}

void	ezrl_endall(t_ezrl *rl_ptr)
{
	if (rl_ptr == NULL)
		return ;
	free(rl_ptr->input);
	ezrl_destroy_history(rl_ptr);
	(*rl_ptr) = ezrl_init();
	rl_clear_history();
}
