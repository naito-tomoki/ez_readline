/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_wrapper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaito <tnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:14:35 by tnaito            #+#    #+#             */
/*   Updated: 2025/12/16 03:00:27 by tnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RL_WRAPPER_H
# define RL_WRAPPER_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# include <stdbool.h>

bool	rlwp_is_safe_add_history(const char *line);
bool	rlwp_add_history(const char *line);
char	**rlwp_completion_setting(
			const char *text, int start, int end);

#endif
