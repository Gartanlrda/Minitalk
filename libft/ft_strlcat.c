/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:27:55 by ggoy              #+#    #+#             */
/*   Updated: 2024/05/01 10:38:00 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	j = 0;
	while (src[j])
		j++;
	if (i > size)
		return (size + j);
	return (i + j);
}
/*
int	main(void)
{
	char	dest[] = "Bonjour";
	const char src[] = "con";

	printf("%zu""\n", ft_strlcat(dest, src, 0));
	printf("%s", dest);
}*/
