/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ezrl_init_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaito <tnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:55:15 by tnaito            #+#    #+#             */
/*   Updated: 2025/10/22 18:44:08 by tnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ez_readline.h"
#include <stdlib.h>

bool	ezrl_init_t_ezrl(t_ezrl **rl_ptr)
{
	if (rl_ptr == NULL)
		return (false);
	if ((*rl_ptr) != NULL)
		return (false);
	(*rl_ptr) = malloc(sizeof(t_ezrl));
	if ((*rl_ptr) == NULL)
		return (false);
	(*rl_ptr)->stock.history = NULL;
	(*rl_ptr)->stock.next = NULL;
	return (true);
}
