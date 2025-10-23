/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ezrl_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaito <tnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 23:15:29 by tnaito            #+#    #+#             */
/*   Updated: 2025/10/23 23:19:27 by tnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ez_readline.h"
#include "utils.h"

bool	ezrl_isspace_all(const char *line)
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
