/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:19:54 by ggoy              #+#    #+#             */
/*   Updated: 2024/04/25 18:19:40 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>

void	*ft_bzero(void *buff, size_t l)
{
	size_t		i;
	char		*ptr;

	i = 0;
	ptr = (char *)buff;
	while (i < l)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
/*
int	main(void)
{
    char DuplicateString[255];
    ft_bzero(&DuplicateString,50);
    DuplicateString[50] = 0;
    printf("DuplicateString = %s\n",DuplicateString);
    return 0;
}*/
