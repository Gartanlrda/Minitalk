/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartan <gartan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 00:42:54 by ggoy              #+#    #+#             */
/*   Updated: 2024/08/07 15:57:12 by gartan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# include <stdlib.h>

int		ft_strlens(char *s);
int		ft_check(char *s);
char	*get_next_line(int fd);
char	*ft_strjoins(char *s1, char *s2, int len);
char	*ft_strdups(char *s);
// void	free_strs(char **s1, char **s2, char **s3);

#endif
