/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:30:19 by rmarquar          #+#    #+#             */
/*   Updated: 2024/02/06 12:31:45 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// The function ft_strlen counts the number of characters in a string.
// It takes a string as a parameter and returns the number of characters in it.
// This function is from my own libft.h!!!
// regards from Robin Marquardt

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (*str++)
		i++;
	return (i);
}

// The function ft_strchr returns a pointer
// to the first occurrence of the
// character c in the string s.
// This function is from my own libft.h!!!
// regards from Robin Marquardt

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	ch;

	i = 0;
	ch = c;
	if (ch == '\0')
	{
		i = ft_strlen(s);
		return ((char *)s + i);
	}
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

// This function copies n bytes from memory area src to memory area dest.
// The memory areas must not overlap.
// This function is from my own libft.h!!!
// regards from Robin Marquardt

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	const char		*s;
	size_t			i;

	i = 0;
	d = dest;
	s = src;
	if ((dest == NULL && src == NULL))
		return (NULL);
	while (i++ < n)
		*d++ = *s++;
	return (dest);
}

// The function ft_strcpy copies the string from s2 to s1.
// It takes two strings as parameters and returns the copied string.
// This function is from my own libft.h!!!
// regards from Robin Marquardt

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = s2[i];
	return (s1);
}
