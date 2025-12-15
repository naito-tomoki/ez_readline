/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_wrapper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaito <tnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:04:04 by tnaito            #+#    #+#             */
/*   Updated: 2025/12/16 02:55:56 by tnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rl_wrapper.h"
#include "libft.h"
#include <stdlib.h>

bool	rlwp_is_safe_add_history(const char *line)
{
	if (line == NULL)
		return (false);
	if (ft_strlen(line) == 0)
		return (false);
	return (true);
}

// reject only '\n'
bool	rlwp_add_history(const char *line)
{
	if (!rlwp_is_safe_add_history(line))
		return (false);
	add_history(line);
	return (true);
}

char	**rlwp_completion_setting(
	const char *text, int start, int end)
{
	rl_attempted_completion_over = (
			(start == 0) && (ft_strlen(text) == 0));
	return (NULL);
	(void)end;
}
