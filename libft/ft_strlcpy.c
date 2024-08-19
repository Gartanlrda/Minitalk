/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:38:34 by ggoy              #+#    #+#             */
/*   Updated: 2024/04/28 10:40:50 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
/*
int	main(void)
{
	char	dest[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 0};
	const char	src[10] = {5, 5, 5, 0, 0, 0, 0, 0, 0, 0};

	printf("%zu", ft_strlcpy(dest, src, 5));
	return(0);
}*/
