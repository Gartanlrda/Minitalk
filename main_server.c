/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:38:09 by ggoy              #+#    #+#             */
/*   Updated: 2024/08/22 09:39:05 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	decode(int sign, siginfo_t *info, void *context)
{
	static int		client = 0;
	static int		bit = 0;
	static char		c = 0;

	(void)context;
	info->si_pid;
	if (sign == SIGUSR1)
		c |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (client < 100000)
		{
			client = client * 10 + (c - 48);
			c = 0;
			bit = 0;
			return ;
		}
		if (c == '\0')
			client = 0 * kill(client, SIGUSR1);
		ft_putchar(c);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	sign;

	sign.sa_sigaction = decode;
	sigemptyset(&sign.sa_mask);
	sign.sa_flags = 0;
	ft_printf("[SERVER PID]: -%i-\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sign, NULL);
		sigaction(SIGUSR2, &sign, NULL);
	}
}
