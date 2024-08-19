/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:31:11 by ggoy              #+#    #+#             */
/*   Updated: 2024/04/27 16:26:28 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest2;
	const char	*src2;

	i = 0;
	dest2 = dest;
	src2 = src;
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest2);
}
/*
int main() {
 char A[12];
 char B[15];
 int I;
 for(I=0; I < 12; I++) {
  A[I] = I;
 }
 ft_memcpy(&B,&A,12);
 for(I=0; I < 12; I++) {
  printf("B[%i] = %i\n",I,B[I]);
 }
 return 0;
}*/
