/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:31:18 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/12 11:23:00 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_server	g_server;

void	ft_init_server(void)
{
	g_server.client_pid = 0;
	g_server.message = NULL;
	g_server.bit_index = 0;
	g_server.char_index = 0;
	g_server.current_char = 0;
}

void	ft_handler_signal(int signum, siginfo_t *info, void *context)
{
	(void)context;
	ft_prepare_client(info);
	ft_process_bit(signum);
	kill(info->si_pid, SIGUSR1);
}

void	ft_setup_signal_handler(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = ft_handler_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Error configuring SIGUSR1\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Error configuring SIGUSR2\n");
}

int	main(void)
{
	ft_init_server();
	ft_printf("🚀 Server started!\n");
	ft_printf("Server PID: %d\n", getpid());
	ft_printf("Waiting for messages...\n");
	ft_setup_signal_handler();
	while (1)
		pause();
	return (0);
}
