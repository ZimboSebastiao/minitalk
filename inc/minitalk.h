/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:31:40 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/12 11:32:42 by zimbo            ###   ########.fr       */
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

extern volatile sig_atomic_t	g_confirmation_received;
extern t_server					g_server;

void	ft_send_char(int pid, char c);
void	ft_send_message(int pid, char *str);
void	ft_handler_signal(int signum, siginfo_t *info, void *context);
void	ft_setup_signal_handler(void);
void	ft_prepare_client(siginfo_t *info);
void	ft_process_bit(int signum);
void	ft_wait_confirmation(void);
void	ft_send_bit(int pid, int bit);
void	ft_init_server(void);

#endif
