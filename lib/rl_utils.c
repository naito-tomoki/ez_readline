/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaito <tnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 23:15:29 by tnaito            #+#    #+#             */
/*   Updated: 2025/10/24 21:12:02 by tnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rl_wrapper.h"
#include "utils.h"

bool	rl_isspace_all(const char *line)
{
	if (line == NULL)
		return (false);
	while (*line)
	{
		if (ft_isspace(*line) == false)
			return (false);
	}
	return (true);
}
