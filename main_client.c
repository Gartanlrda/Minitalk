/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:38:13 by ggoy              #+#    #+#             */
/*   Updated: 2024/08/27 18:53:01 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

bool	g_run = false;

// static void	ft_wait_signal(int sign, siginfo_t *info, void *context)
// {
// 	info = 0;
// 	(void)context;
// 	ft_printf("bjr\n");
// 	if (g_run == false || sign == SIGUSR1)
// 		g_run = true;
// 	// else
// 	// 	g_run = false;
// }

static void	encode(int pid, char c)
{
	int	i = 0;	

	if (i == 8)
		i = 0;
	while (i < 8)
	{
		if (c & (0x01 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		while (g_run == false)
		{
			usleep(200);
			;
			// sigaction(SIGUSR1, &run, NULL);?
		}
		g_run = false;
	}

}

// static void	encode_pid(int pid, char c)
// {
// 	static int	i = 0;

// 	printf("%c\n", c);
// 	if (i == 8)
// 		i = 0;
// 	while (i < 8)
// 	{
// 		if (c & (0x01 << i))
// 			kill(pid, SIGUSR1);
// 		else
// 			kill(pid, SIGUSR2);
// 		i++;
// 		usleep(400);
// 	}
// }
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
	// char				*client;
	int					server;
	int					i;
	struct sigaction	sign;
	// struct sigaction	run;

	sign.sa_sigaction = say_ok;
	sigemptyset(&sign.sa_mask);
	sign.sa_flags = SA_SIGINFO;
	// run.sa_sigaction = ft_wait_signal;
	// sigemptyset(&run.sa_mask);
	// run.sa_flags = 0;
	if (argc == 3)
	{
		i = -1;
		server = ft_atoi(argv[1]);
		// client = ft_itoa(getpid());
		printf("I am %d\n", getpid());
		ft_printf("Envoi du message a %d en cours..\n", server);
		// sigaction(SIGUSR1, &run, NULL);
		// while (++i < ft_strlens(client))
		// 	encode_pid(server, client[i]);
		i = -1;
		// free(client);
		sigaction(SIGUSR2, &sign, NULL);
		sigaction(SIGUSR1, &sign, NULL);
		while (++i < ft_strlens(argv[2]))
			encode(server, argv[2][i]);
	}
}
