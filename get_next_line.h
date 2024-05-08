/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:44:36 by rmarquar          #+#    #+#             */
/*   Updated: 2024/02/06 12:30:51 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Main functions
void		ft_free(char **ptr);
char		*ft_lets_go(int fd, char *remainder,
				char *temp, size_t remainder_len);
char		*ft_remainder(char *line);
char		*get_next_line(int fd);
char		*allocate_and_copy(char *remainder, char *temp,
				size_t remainder_len, int i);

// Libft functions
char		*ft_strcpy(char *s1, char *s2);
int			ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
void		*ft_memcpy(void *dest, const void *src, size_t n);

#endif
