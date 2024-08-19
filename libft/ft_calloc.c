/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:40:09 by ggoy              #+#    #+#             */
/*   Updated: 2024/05/01 09:50:17 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	*ft_calloc(size_t nb, size_t size)
{
	char		*result;
	size_t		i;
	size_t		total;

	if (size && nb > (size_t)-1 / size)
		return (NULL);
	i = 0;
	total = size * nb;
	result = malloc(total);
	if (!result)
		return (NULL);
	while (i < total)
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}
/*
int	main(void)
{
	char	*result;
	int	i;
	
	result = ft_calloc(15, sizeof(char));
	//printf("%s\n", result);
	for (i = 0; i < 15; i++)
	{
		printf("result[%d] = %d\n", i, result[i]);
	}
}*/
