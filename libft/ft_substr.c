/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:43:42 by ggoy              #+#    #+#             */
/*   Updated: 2024/05/01 05:56:13 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	size_t			i;
	unsigned int	j;
	int				mallocizer;

	if (!s)
		return (NULL);
	i = 0;
	j = start;
	mallocizer = (int) len;
	if (len == 0 || ((unsigned int)ft_strlen(s) <= start) || (!s[i]))
		mallocizer = 0;
	else if ((unsigned int) len > ((unsigned int) ft_strlen(s) - start))
		mallocizer = (int) ft_strlen(s) - (int) start;
	result = malloc(sizeof(char) * mallocizer + 1);
	while (mallocizer != 0 && s[j] && j <= len + start - 1)
	{
		result[i] = s[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}
/*
int	main(void)
{
	printf("%s\n", ft_substr("tripouille", 1, 1));
}*/
