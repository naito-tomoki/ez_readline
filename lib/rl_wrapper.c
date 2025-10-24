/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_wrapper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaito <tnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:04:04 by tnaito            #+#    #+#             */
/*   Updated: 2025/10/24 20:47:26 by tnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rl_wrapper.h"
#include <stdlib.h>

bool	rlwp_add_history(const char *line)
{
	if (line == NULL)
		return (false);
	if (ezrl_isspace_all(line))
		return (false);
	add_history(line);
	return (true);
}
