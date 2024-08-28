/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:38:09 by ggoy              #+#    #+#             */
/*   Updated: 2024/08/28 15:59:59 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_msg = NULL;

static char	*minitalk_join(char c)
{
	int		mallocizer;
	int		i;
	char	*result;

	i = 0;
	if (g_msg == NULL)
	{
		result = malloc(sizeof(char) * 2);
		result[0] = c;
		result[1] = '\0';
		return (result);
	}
	mallocizer = ft_strlen(g_msg) + 1;
	result = malloc(sizeof(char) * (mallocizer + 1));
	while (g_msg[i])
	{
		result[i] = g_msg[i];
		i++;
	}
	result[i] = c;
	result[++i] = '\0';
	free(g_msg);
	return (result);
}

static void	decode(int sign, siginfo_t *info, void *context)
{
	pid_t			client;
	static int		bit = 0;
	static char		c = 0;

	(void)context;
	client = info->si_pid;
	if (sign == SIGUSR1)
		c |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		g_msg = minitalk_join(c);
		if (c == '\0')
		{
			kill(client, SIGUSR2);
			ft_putstr_fd(g_msg, 0);
			free(g_msg);
			g_msg = NULL;
		}
		c = 0;
		bit = 0;
	}
	usleep(200);
	kill(client, SIGUSR1);
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
