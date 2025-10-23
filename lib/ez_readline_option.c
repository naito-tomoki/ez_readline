/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ez_readline_option.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaito <tnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 22:22:10 by tnaito            #+#    #+#             */
/*   Updated: 2025/10/23 22:42:20 by tnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ez_readline.h"
#include "libft.h"

bool	ezrl_set_conn_str(const char *s, t_ezrl *rl_ptr)
{
	if (s == NULL || rl_ptr == NULL)
		return (false);
	rl_ptr->conn_str = s;
	rl_ptr->conn_str_len = ft_strlen(s);
	return (true);
}
