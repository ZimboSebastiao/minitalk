/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_states.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 10:51:11 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/12 10:53:41 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_prepare_client(siginfo_t *info)
{
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
}

void	ft_process_bit(int signum)
{
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
}
