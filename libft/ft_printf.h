/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:21:38 by ggoy              #+#    #+#             */
/*   Updated: 2024/05/07 16:30:44 by ggoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_putstr(char *s, int count);
int		ft_putnbr(long long nb, int count);
int		ft_put_base(unsigned long nb, int count, char *base, unsigned int lenb);
int		ft_put_address(unsigned long ptr, int count);
void	ft_putchar(char c);
#endif
