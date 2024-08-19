/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:20:37 by ggoy              #+#    #+#             */
/*   Updated: 2024/05/01 06:49:01 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			return ((char *)s + i);
		++i;
	}
	return (0);
}
/*
int	main(void)
{
	const char	s[] = "tripouille";
	int	c = 0;
	printf("%s\n", (strchr(s, c)));
	printf("%s\n", (ft_strchr(s, c)));
}*/
