/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:09:48 by ggoy              #+#    #+#             */
/*   Updated: 2024/05/01 05:20:00 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include <stdio.h>
#include <limits.h>

char	*ft_strnstr(const char *large, const char *small, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(small[i]))
		return ((char *)large);
	while (i < len && large[i])
	{
		j = 0;
		if (large[i] == small[j])
		{
			while (small[j] == large[i + j] && (i + j) < len)
				j++;
			if (small[j] == '\0')
				return ((char *)large + i);
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	large[] = "";
	const char	small[] = "Charly";

	printf("%s\n", strnstr(large, small, -1));
	printf("%s\n", ft_strnstr(large, small, -1));
}*/
