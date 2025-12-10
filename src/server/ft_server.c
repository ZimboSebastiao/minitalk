/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:31:18 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/10 00:16:32 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_server	g_server;

static void	ft_init_server(void)
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

	if (g_server.client_pid == 0)
	{
		g_server.client_pid = info->si_pid;
		g_server.message = ft_calloc(10000, sizeof(char));
		if (!g_server.message)
			exit(1);
	}
	else if (g_server.client_pid != info->si_pid)
	{
		free(g_server.message);
		ft_init_server();
		g_server.client_pid = info->si_pid;
		g_server.message = ft_calloc(10000, sizeof(char));
		if (!g_server.message)
			exit(1);
	}
	if (signum == SIGUSR1)
		g_server.current_char |= (1 << g_server.bit_index);
	g_server.bit_index++;
	if (g_server.bit_index == 8)
	{
		if (g_server.current_char == '\0')
		{
			ft_printf("%s\n", g_server.message);
			free(g_server.message);
			ft_init_server();
		}
		else
		{
			g_server.message[g_server.char_index] = g_server.current_char;
			g_server.char_index++;
			g_server.bit_index = 0;
			g_server.current_char = 0;
		}
	}
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
	ft_printf("📡 Server PID: %d\n", getpid());
	ft_printf("⏳ Waiting for messages...\n");
	ft_setup_signal_handler();
	while (1)
		pause();
	return (0);
}
