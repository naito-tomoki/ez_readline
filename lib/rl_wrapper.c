/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_wrapper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaito <tnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:04:04 by tnaito            #+#    #+#             */
/*   Updated: 2025/12/17 03:16:46 by tnaito           ###   ########.fr       */
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

int	rlwp_countlines(const char *str)
{
	int			res;
	const char	linec = '\n';

	if (str == NULL)
		return (-1);
	if (!rlwp_add_history(str))
		return (0);
	res = 1;
	str = ft_strchr(str, linec);
	while (str)
	{
		res++;
		str = ft_strchr(++str, linec);
	}
	return (res);
}
