/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:31:40 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/10 00:12:30 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "../lib/libft.h"
# include "../lib/ft_printf/ft_printf.h"

typedef struct s_server
{
	int		client_pid;
	char	*message;
	int		bit_index;
	int		char_index;
	char	current_char;
}	t_server;

void	ft_send_char(int pid, char c);
void	ft_send_message(int pid, char *str);
void	ft_handle_signal(int signum, siginfo_t *info, void *context);
void	ft_setup_signal_handler(void);

#endif