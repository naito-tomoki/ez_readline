/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ez_readline_history.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaito <tnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:50:39 by tnaito            #+#    #+#             */
/*   Updated: 2025/10/22 23:50:54 by tnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ez_readline.h"
#include <stdlib.h>

static t_ezrl_stock	*ezrl_history_last(t_ezrl_stock *history)
{
	while (history->next)
		history = history->next;
	return (history);
}

void	ezrl_set_history_stock(t_ezrl_stock *history)
{
	clear_history();
	while (history)
	{
		add_history(history->history);
		history = history->next;
	}
}

bool	ezrl_add_history(t_ezrl *rl_ptr)
{
	t_ezrl_stock	*stock;

	if (rl_ptr == NULL)
		return (false);
	if (rl_ptr->input_type == RL_NOSTOCK)
		return (true);
	stock = malloc(sizeof(t_ezrl_stock));
	if (stock == NULL)
		return (false);
	stock->history = rl_ptr->input;
	stock->next = NULL;
	if (rl_ptr->history == NULL)
		rl_ptr->history = stock;
	else
		ezrl_history_last(rl_ptr->history)->next = stock;
	if (rl_ptr->input_type == RL_INPUT)
		add_history(stock->history);
	else
		ezrl_set_history_stock(rl_ptr->history);
	rl_ptr->input = NULL;
	rl_ptr->input_type = RL_NOSTOCK;
	return (true);
}

void	ezrl_destroy_history(t_ezrl *rl_ptr)
{
	t_ezrl_stock	*next;

	if (rl_ptr == NULL)
		return ;
	free(rl_ptr->input);
	while (rl_ptr->history)
	{
		next = (rl_ptr->history)->next;
		free((rl_ptr->history)->history);
		free(rl_ptr->history);
		rl_ptr->history = next;
	}
}
