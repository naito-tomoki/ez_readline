/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_wrapper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaito <tnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:04:04 by tnaito            #+#    #+#             */
/*   Updated: 2025/10/24 21:27:44 by tnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rl_wrapper.h"
#include "libft.h"
#include <stdlib.h>

// reject only '\n'
bool	rlwp_add_history(const char *line)
{
	if (line == NULL)
		return (false);
	if ((ft_strlen(line) == 1) && (line[0] == '\0'))
		return (false);
	add_history(line);
	return (true);
}
