/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ez_readline_option.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaito <tnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 22:22:10 by tnaito            #+#    #+#             */
/*   Updated: 2025/12/14 19:03:17 by tnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ez_readline.h"
#include "libft.h"
#include <stdlib.h>

bool	ezrl_set_conn_str(const char *s, t_ezrl *rl_ptr)
{
	if (s == NULL || rl_ptr == NULL)
		return (false);
	rl_ptr->conn_info.conn_str = s;
	rl_ptr->conn_info.conn_str_len = ft_strlen(s);
	return (true);
}

bool	ezrl_set_histsize(int histsize, t_ezrl *rl_ptr)
{
	if (rl_ptr == NULL)
		return (false);
	rl_ptr->history_size = histsize;
	ezrl_rm_over_histsize(rl_ptr);
	return (true);
}

bool	ezrl_rm_oldest_history(t_ezrl *rl_ptr)
{
	t_ezrl_history	*oldest;
	t_ezrl_history	*next;

	if (rl_ptr == NULL)
		return (false);
	oldest = rl_ptr->history;
	if (oldest == NULL)
		return (false);
	next = oldest->next;
	free(oldest->recode);
	free(oldest);
	rl_ptr->history = next;
	return (true);
}
