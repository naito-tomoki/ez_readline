/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ez_readline_history.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaito <tnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:50:39 by tnaito            #+#    #+#             */
/*   Updated: 2025/10/24 21:17:36 by tnaito           ###   ########.fr       */
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

void	ezrl_set_history_stock(t_ezrl_history *history)
{
	clear_history();
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
	if (rl_ptr->input_type == RL_INPUT)
		add_history(stock->recode);
	else
		ezrl_set_history_stock(rl_ptr->history);
	rl_ptr->input = NULL;
	rl_ptr->input_type = RL_NOSTOCK;
	return (true);
}

void	ezrl_destroy_history(t_ezrl *rl_ptr)
{
	t_ezrl_history	*next;

	if (rl_ptr == NULL)
		return ;
	while (rl_ptr->history)
	{
		next = (rl_ptr->history)->next;
		free((rl_ptr->history)->recode);
		free(rl_ptr->history);
		rl_ptr->history = next;
	}
}
