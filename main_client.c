/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:38:13 by ggoy              #+#    #+#             */
/*   Updated: 2024/08/29 10:58:30 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

bool	g_run = false;

static void	encode(int pid, char c)
{
	int	i;	

	i = 0;
	while (i < 8)
	{
		if (c & (0x01 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		while (g_run == false)
			usleep(200);
		g_run = false;
	}
}

static void	say_ok(int sign, siginfo_t *info, void *context)
{
	info = 0;
	(void)context;
	if (sign == SIGUSR2)
	{
		ft_printf("Message envoye avec succes!\n");
		exit (EXIT_SUCCESS);
	}
	else if (g_run == false && sign == SIGUSR1)
		g_run = true;
}

int	main(int argc, char **argv)
{
	int					server;
	int					i;
	struct sigaction	sign;

	sign.sa_sigaction = say_ok;
	sigemptyset(&sign.sa_mask);
	sign.sa_flags = SA_SIGINFO;
	if (argc == 3)
	{
		i = -1;
		server = ft_atoi(argv[1]);
		ft_printf("Envoi du message a %d en cours..\n", server);
		i = -1;
		sigaction(SIGUSR2, &sign, NULL);
		sigaction(SIGUSR1, &sign, NULL);
		while (++i < ft_strlens(argv[2]))
			encode(server, argv[2][i]);
		encode(server, '\n');
		encode(server, '\0');
	}
}
