/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <ggoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:38:09 by ggoy              #+#    #+#             */
/*   Updated: 2024/08/19 16:24:57 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	char	*line;
	
	ft_printf("[SERVER PID]: -%i-\n", getpid());
	while (1)
	{
		line = get_next_line(1);
		if (ft_strcmp(line, "exit\n") == 0)
			break;
		else
			ft_printf("\033[1A\033[2K");
		free(line);
	}
}