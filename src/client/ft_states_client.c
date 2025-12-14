/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_states_client.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 11:09:40 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/12 11:36:32 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_wait_confirmation(void)
{
	int	timeout;

	timeout = 0;
	while (!g_confirmation_received && timeout < 1000)
	{
		usleep(1000);
		timeout++;
	}
	if (timeout >= 1000)
	{
		ft_printf("❌ Error: No confirmation from server\n");
		exit(1);
	}
}

void	ft_send_bit(int pid, int bit)
{
	int	signal_to_send;

	g_confirmation_received = 0;
	if (bit == 1)
		signal_to_send = SIGUSR1;
	else
		signal_to_send = SIGUSR2;
	if (kill(pid, signal_to_send) == -1)
	{
		ft_printf("❌ Error: Cannot send signal to PID %d\n", pid);
		exit(1);
	}
	ft_wait_confirmation();
}
