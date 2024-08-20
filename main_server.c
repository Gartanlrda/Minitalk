/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:38:09 by ggoy              #+#    #+#             */
/*   Updated: 2024/08/20 17:36:47 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int client;
int	server;

static void decode(int sign)
{
	int i;
	static int bit = 7;
    static char c = 0;

	i = 0;
	kill(client, SIGUSR2);
    if (sign > 0)
    {
        if (sign == SIGUSR1)
            c += (1 << bit);
        bit--;
    }
    if (bit == -1)
    {
        ft_putchar(c);
        c = 0;
        bit = 7;
		kill(client, SIGUSR1);
    }
}

static void	decode_pid(int sign)
{
	int i;
	static int bit = 7;
    static char c = 0;

	i = 0;
    if (sign > 0)
    {
        if (sign == SIGUSR1)
            c += (1 << bit);
        bit--;
    }
    if (bit == -1)
    {
        client = client * 10 + (c - 0);
        c = 0;
        bit = 7;
    }
}

static int	valid_pid(int pid)
{
	if (ft_strlen(ft_itoa(pid)) < 5)
		return (0);
	else
		return (1);
}

int	main(void)
{
	char	*line;
	
	server = getpid();
	ft_printf("[SERVER PID]: -%i-\n", server);
	while (1)
	{
		while (valid_pid(client) != 1)
		{		
			signal(SIGUSR1, decode_pid);
			signal(SIGUSR2, decode_pid);
		}
		signal(SIGUSR1, decode);
		signal(SIGUSR2, decode);
		line = get_next_line(1);
		if (ft_strcmp(line, "exit\n") == 0)
			break;
		else
			ft_printf("\033[1A\033[2K");
		free(line);
	}
}
