/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:58:34 by ggoy              #+#    #+#             */
/*   Updated: 2024/04/30 01:17:04 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_splitercell(char const *s, char c)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] && s[i] == c)
				i++;
		}
		else
		{
			result++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (result);
}

static int	sp(const char *s, int start, char c)
{
	int	i;

	i = 0;
	while (start + i < ((int)ft_strlen(s)) && s[start + i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**re;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = -1;
	re = ft_calloc(sizeof(char *), ft_splitercell(s, c) + 1);
	while (s && s[i] && j < (ft_splitercell(s, c)))
	{
		if (s[i] == c)
			while (s && s[i] && s[i] == c)
				i++;
		else
		{
			j++;
			k = 0;
			re[j] = ft_calloc(sizeof(char), sp(s, i, c) + 1);
			while (s[i] && s[i] != c)
				re[j][k++] = s[i++];
		}
	}
	return (re);
}
/*
int	main(void)
{
	char	s[] = "   Bonjour  connard     de    maaarde  .";
	char	c = ' ';
	int	i;
	char	**result;

	result = ft_split(s, c);
	i = 0;
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		i++;
	}
}*/
