/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:38:13 by ggoy              #+#    #+#             */
/*   Updated: 2024/08/20 17:40:24 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int client;

static void    encode(int pid, unsigned char *encode)
{
    static const int signals[] = {SIGUSR2, SIGUSR1};
	unsigned int i;
	
	i = 1;
    while (*encode)
    {
        i = 1 << 7;
        while (i)
        {
			if (*encode & i)
            	kill(pid, signals[1]);
			else
            	kill(pid, signals[0]);
            i >>= 1;
			if (signal(SIGUSR1, NULL))
				pause;
        }
        encode++;
    }
}

static void    encode_pid(int pid, unsigned char *encode)
{
    static const int signals[] = {SIGUSR2, SIGUSR1};
	unsigned int i;
	
	i = 1;
    while (*encode)
    {
        i = 1 << 7;
        while (i)
        {
			if (*encode & i)
            	kill(pid, signals[1]);
			else
            	kill(pid, signals[0]);
            i >>= 1;
			usleep(100);
        }
        encode++;
    }
}

int	main(int argc, char **argv)
{
	client = getpid();
	if (argc == 3)
	{
		encode_pid(ft_atoi(argv[1]), ft_itoa((unsigned char*)client));
		encode(ft_atoi(argv[1]), (unsigned char*)argv[2]);
	}
}