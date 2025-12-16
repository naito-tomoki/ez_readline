/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ez_readline_history.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaito <tnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:50:39 by tnaito            #+#    #+#             */
/*   Updated: 2025/12/17 03:02:05 by tnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ez_readline.h"
#include "rl_wrapper.h"
#include <stdlib.h>

static t_ezrl_history	*ezrl_history_last(t_ezrl_history *history)
{
	while (history->next)
		history = history->next;
	return (history);
}

void	ezrl_rm_over_histsize(t_ezrl *rl_ptr)
{
	int	histsize;
	int	over;
	int	i;

	if (rl_ptr == NULL)
		return ;
	histsize = rl_ptr->history_size;
	if (histsize < 0)
		return ;
	over = ezrl_get_history_count(rl_ptr) - histsize;
	i = 0;
	while (i < over)
	{
		ezrl_rm_oldest_history(rl_ptr);
		i++;
	}
	if (i)
		ezrl_set_history_stock(rl_ptr);
}

void	ezrl_set_history_stock(t_ezrl *rl_ptr)
{
	t_ezrl_history	*history;

	history = rl_ptr->history;
	rl_clear_history();
	while (history)
	{
		add_history(history->recode);
		history = history->next;
	}
}

bool	ezrl_add_history(t_ezrl *rl_ptr)
{
	t_ezrl_history	*stock;

	if (rl_ptr == NULL)
		return (false);
	if (rl_ptr->input_type == RL_NOSTOCK)
		return (true);
	stock = malloc(sizeof(t_ezrl_history));
	if (stock == NULL)
		return (false);
	stock->recode = rl_ptr->input;
	stock->next = NULL;
	if (rl_ptr->history == NULL)
		rl_ptr->history = stock;
	else
		ezrl_history_last(rl_ptr->history)->next = stock;
	if (rl_ptr->input_type == RL_AGAIN)
		ezrl_set_history_stock(rl_ptr);
	ezrl_rm_over_histsize(rl_ptr);
	rl_ptr->input = NULL;
	rl_ptr->input_type = RL_NOSTOCK;
	return (true);
}

void	ezrl_destroy_history(t_ezrl *rl_ptr)
{
	if (rl_ptr == NULL)
		return ;
	while (rl_ptr->history)
		ezrl_rm_oldest_history(rl_ptr);
}
