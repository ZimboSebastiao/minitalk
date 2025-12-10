/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:31:23 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/10 00:15:17 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_confirmation_received = 0;

void	ft_confirmation_handler(int signum)
{
	(void)signum;
	g_confirmation_received = 1;
}

void	ft_send_char(int pid, char c)
{
	int	bit;
	int	i;
	
	i = 0;
	while (i < 8)
	{
		bit = (c >> i) & 1;
		g_confirmation_received = 0;
		
		if (bit == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_confirmation_received)
			usleep(50);
		
		i++;
	}
}

void	ft_send_message(int pid, char *str)
{
	int	i;

	signal(SIGUSR1, ft_confirmation_handler);
	i = 0;
	while (str[i])
	{
		ft_send_char(pid, str[i]);
		i++;
	}
	ft_send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	int	pid;
	
	if (argc != 3)
	{
		ft_printf("❌ Use: %s <Server PID> <message>\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("❌ Invalid PID\n");
		return (1);
	}
	ft_printf("📤 Sending message to the server with PID %d\n", pid);
	ft_printf("📝 Message: %s\n", argv[2]);
	ft_send_message(pid, argv[2]);
	ft_printf("✅ Message sent successfully!\n");
	return (0);
}