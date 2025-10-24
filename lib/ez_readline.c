/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ez_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaito <tnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:13:50 by tnaito            #+#    #+#             */
/*   Updated: 2025/10/24 21:40:16 by tnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ez_readline.h"
#include "libft.h"
#include <stdlib.h>

t_ezrl	ezrl_init(void)
{
	t_ezrl	rl;

	rl.input = NULL;
	rl.conn_info.conn_str = " ";
	rl.conn_info.conn_str_len = 1;
	rl.history = NULL;
	rl.input_type = RL_NOSTOCK;
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

char	*ez_readline(const char *prompt, t_ezrl *rl_ptr)
{
	char	*line;

	if (rl_ptr == NULL)
		return (NULL);
	line = readline(prompt);
	if (line == NULL)
		return (NULL);
	if (ezrl_conn_input(line, rl_ptr) == false)
	{
		free(line);
		return (NULL);
	}
	if (rl_ptr->input_type != RL_NOSTOCK)
		ezrl_set_history_stock(rl_ptr->history);
	add_history(rl_ptr->input);
	rl_ptr->input_type = ezrl_add_input_type(rl_ptr->input_type);
	return (rl_ptr->input);
}

void	ezrl_endall(t_ezrl *rl_ptr)
{
	if (rl_ptr == NULL)
		return ;
	free(rl_ptr->input);
	ezrl_destroy_history(rl_ptr);
	(*rl_ptr) = ezrl_init();
	clear_history();
}
