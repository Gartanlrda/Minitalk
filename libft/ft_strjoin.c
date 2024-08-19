/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:48:25 by ggoy              #+#    #+#             */
/*   Updated: 2024/04/29 17:06:41 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_mallocizer(char const *s1, char const *s2)
{
	int	mallocizer;

	if (!s1 && s2)
		mallocizer = ft_strlen(s2);
	else if (!s2 && s1)
		mallocizer = ft_strlen(s1);
	else if (s1 && s2)
		mallocizer = ft_strlen(s1) + ft_strlen(s2);
	else
		mallocizer = 0;
	return (mallocizer);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		mallocizer;
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = -1;
	mallocizer = ft_mallocizer(s1, s2);
	result = malloc(sizeof(char) * (mallocizer + 1));
	if (!result)
		return (NULL);
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2 && s2[++j])
	{
		result[i] = s2[j];
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
int	main(void)
{
	printf("%s\n", ft_strjoin("", "connard"));
}*/
