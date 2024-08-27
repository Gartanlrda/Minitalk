/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:38:09 by ggoy              #+#    #+#             */
/*   Updated: 2024/08/27 18:56:28 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	decode(int sign, siginfo_t *info, void *context)
{
	pid_t			client;
	static int		bit = 0;
	static char		c = 0;

	(void)context;
	client = info->si_pid;
	// printf("pid: %i\n", info->si_uid);
	if (sign == SIGUSR1)
		c |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		// if (client < 100000)
		// {
		// 	client = client * 10 + (c - 48);
		// 	c = 0;
		// 	bit = 0;
		// 	printf("%i\n", client);
		// 	return ;
		// }
		if (c == '\0')
			kill(client, SIGUSR2);
			// client = 0 * kill(client, SIGUSR2);
		ft_putchar(c);
		c = 0;
		bit = 0;
	}
	usleep(200);
	if (kill(client, SIGUSR1) < 0)
		printf("h\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	sign;

	argv[1] = NULL;
	if (argc > 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	else
	{
		sign.sa_sigaction = decode;
		sigemptyset(&sign.sa_mask);
		sign.sa_flags = SA_SIGINFO;
		ft_printf("[SERVER PID]: -%i-\n", getpid());
		while (1)
		{
			sigaction(SIGUSR1, &sign, NULL);
			sigaction(SIGUSR2, &sign, NULL);
		}
	}
}
