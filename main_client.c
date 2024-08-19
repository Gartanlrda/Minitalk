/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:38:13 by ggoy              #+#    #+#             */
/*   Updated: 2024/08/19 17:21:39 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	char	*line;
	
	if (argc == 2 && check_pid(ft_atoi(argv[1])) == 1)
	{
		while (1)
		{
			line = get_next_line(1);
			if (ft_strcmp(line, "exit\n") == 0)
				break;
			else
			{
				ft_printf("\033[1A\033[2K");
			}
			free(line);
		}
	}
}