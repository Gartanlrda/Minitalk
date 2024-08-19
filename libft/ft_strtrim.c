/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:57:12 by ggoy              #+#    #+#             */
/*   Updated: 2024/04/29 17:05:28 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static unsigned int	ft_setstart(const char *s1, const char *set)
{
	unsigned int	start;
	unsigned int	i;

	start = 0;
	i = 0;
	if (!s1 || !set)
		return (0);
	while (set[i] && s1)
	{
		i = 0;
		while (set[i] && set[i] != s1[start])
			i++;
		if (!set[i])
			break ;
		start++;
	}
	if (!s1[start])
		return (0);
	return (start);
}

static int	ft_setend(const char *s1, const char *set)
{
	int	end;
	int	i;

	end = ft_strlen(s1) - 1;
	i = 0;
	if (!s1)
		return (0);
	if (!set)
		return (ft_strlen(s1) - 1);
	while (set[i] && s1)
	{
		if (set[i] == s1[end])
		{
			i = 0;
			end--;
		}
		else
			i++;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		start;
	int			len;
	size_t		end;
	char		*result;

	if (!s1)
		return (NULL);
	i = 0;
	start = ft_setstart(s1, set);
	end = ft_setend(s1, set);
	len = end - start + 1;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	while ((int)i < len)
	{
		result[i] = s1[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}
/*
int	main(void)
{
	const char s1[] = "Fuck it";
	const char set[] = "";

	printf("%s\n", ft_strtrim(s1, NULL));
}*/
