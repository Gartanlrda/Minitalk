/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 01:51:58 by ggoy              #+#    #+#             */
/*   Updated: 2024/04/30 03:58:33 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_itoaizer(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		end;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	end = ft_itoaizer(n) - 1;
	result = ft_calloc(sizeof(char), ft_itoaizer(n) + 1);
	if (!result)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		n = n * -1;
	}
	while (n >= 10)
	{
		result[end] = (n % 10) + '0';
		n = n / 10;
		end--;
	}
	result[end] = n + '0';
	return (result);
}
/*
int	main(void)
{
	printf("%s\n", ft_itoa(-91));
}*/
