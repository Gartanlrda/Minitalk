/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:38:13 by ggoy              #+#    #+#             */
/*   Updated: 2024/08/22 09:57:46 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		usleep(750);
		i++;
	}
}

static void	say_ok(int sign, siginfo_t *info, void *context)
{
	info = 0;
	(void)context;
	if (sign == SIGUSR1)
		ft_printf("Message envoye avec succes!\n");
	exit (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	char				*client;
	int					server;
	int					i;
	struct sigaction	sign;

	sign.sa_sigaction = say_ok;
	sigemptyset(&sign.sa_mask);
	sign.sa_flags = 0;
	if (argc == 3)
	{
		i = -1;
		server = ft_atoi(argv[1]);
		client = ft_itoa(getpid());
		ft_printf("Envoi du message %s en cours..\n", client);
		while (++i < ft_strlens(client))
			encode(server, client[i]);
		i = -1;
		free(client);
		sigaction(SIGUSR1, &sign, NULL);
		while (++i < ft_strlens(argv[2]))
			encode(server, argv[2][i]);
		encode(server, '\n');
		encode(server, '\0');
	}
}
