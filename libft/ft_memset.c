/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:54:14 by ggoy              #+#    #+#             */
/*   Updated: 2024/04/23 18:17:45 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *buff, int c, size_t l)
{
	size_t		i;
	char		*ptr;

	i = 0;
	ptr = buff;
	while (i < l)
	{
		ptr[i] = c;
		i++;
	}
	return (ptr);
}
/*
int	main(void)
{
    char DuplicateString[255];
    ft_memset(&DuplicateString,'*',50);
    DuplicateString[50] = 0;
    printf("DuplicateString = %s\n",DuplicateString);
    return 0;
}*/
