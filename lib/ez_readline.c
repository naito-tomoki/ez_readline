/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ez_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaito <tnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:13:50 by tnaito            #+#    #+#             */
/*   Updated: 2025/10/22 19:11:46 by tnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ez_readline.h"
#include "../libft.h"
#include <stdlib.h>

static bool	ezrl_conn_input(char *line, t_ezrl rl_ptr[static 1])
{
	char	*tmp;
	size_t	prev_len;
	size_t	line_len;

	if (rl_ptr->is_add_history == true)
	{
		rl_ptr->input = line;
		return (true);
	}
	prev_len = ft_strlen(rl_ptr->input);
	line_len = ft_strlen(line);
	tmp = malloc(prev_len + line_len + 1);
	if (tmp == NULL)
		return (false);
	ft_memmove(tmp, rl_ptr->input, prev_len);
	ft_memmove(tmp + prev_len, line, line_len);
	free(line);
	rl_ptr->input = tmp;
	return (true);
}

char	*ez_readline(const char *prompt, t_ezrl **rl_ptr)
{
	char	*line;

	if (!rl_ptr)
		return (NULL);
	line = readline(prompt);
	if (line == NULL)
		return (NULL);
	if ((*rl_ptr) == NULL)
	{
		if (ez_init_t_ezrl(rl_ptr) == false)
		{
			free(line);
			return (NULL);
		}
	}
	if (ezrl_conn_input(line, *rl_ptr) == false)
	{
		free(line);
		free(*rl_ptr);
		return (NULL);
	}
	(*rl_ptr)->is_add_history = false;
	return ((*rl_ptr)->input);
}

char	*ezrl_add_history(t_ezrl *rl)
{
	return (NULL);
}

char	*ezrl_delete_history(t_ezrl *rl, int q)
{
	return (NULL);
}
