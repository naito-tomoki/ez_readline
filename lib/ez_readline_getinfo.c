/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ez_readline_getinfo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaito <tnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 19:02:11 by tnaito            #+#    #+#             */
/*   Updated: 2025/12/17 03:07:41 by tnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ez_readline.h"
#include "libft.h"

int	ezrl_get_history_count(t_ezrl *rl_ptr)
{
	int				count;
	t_ezrl_history	*hist;

	if (rl_ptr == NULL)
		return (-1);
	count = 0;
	hist = rl_ptr->history;
	while (hist)
	{
		count++;
		hist = hist->next;
	}
	return (count);
}

int	ezrl_get_total_inputlines(t_ezrl *rl_ptr)
{
	if (rl_ptr == NULL)
		return (-1);
	return (rl_ptr->total_lines);
}

const char	*ezrl_get_inputing_line(t_ezrl *rl_ptr)
{
	if (rl_ptr == NULL)
		return (NULL);
	return (rl_ptr->input);
}
