/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 00:36:44 by ggoy              #+#    #+#             */
/*   Updated: 2024/08/07 15:56:57 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoins(char *s1, char *s2, int len)
{
	int		mallocizer;
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	mallocizer = ft_strlens(s1) + len;
	result = malloc(sizeof(char) * (mallocizer + 1));
	if (!result)
		return (NULL);
	while (s1 && s1[i] && i < mallocizer && s1 != NULL)
	{
		result[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] && i < mallocizer)
		result[i++] = s2[j++];
	result[i] = '\0';
	if (s1)
		free(s1);
	return (result);
}

char	*ft_strdups(char *s)
{
	int		i;
	char	*result;

	if (!s)
		return (ft_strdups(""));
	i = 0;
	while (s[i])
		i++;
	result = (char *) malloc((i + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	ft_strlens(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
