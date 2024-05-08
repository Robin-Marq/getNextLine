/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:29:40 by rmarquar          #+#    #+#             */
/*   Updated: 2024/02/06 12:33:53 by rmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*allocate_and_copy(char *remainder, char *temp,
			size_t remainder_len, int i)
{
	size_t	new_length;
	char	*new_remainder;

	new_length = remainder_len + i;
	new_remainder = malloc(new_length + 1);
	if (new_remainder == NULL)
	{
		free(remainder);
		return (NULL);
	}
	ft_memcpy(new_remainder, remainder, remainder_len);
	ft_memcpy(new_remainder + remainder_len, temp, i);
	new_remainder[new_length] = '\0';
	free(remainder);
	return (new_remainder);
}

char	*ft_lets_go(int fd, char *remainder, char *temp, size_t remainder_len)
{
	int	i;

	if (remainder == NULL)
		remainder_len = 0;
	else
		remainder_len = ft_strlen(remainder);
	while (1)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i <= 0)
		{
			if (i == -1)
				return (NULL);
			else
				return (remainder);
		}
		temp[i] = '\0';
		remainder = allocate_and_copy(remainder, temp, remainder_len, i);
		if (remainder == NULL)
			return (NULL);
		remainder_len += i;
		if (ft_strchr(temp, '\n'))
			break ;
	}
	return (remainder);
}

char	*ft_remainder(char *line)
{
	size_t	i;
	char	*left_over;

	if (!line)
		return (0);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (0);
	left_over = malloc(ft_strlen(line + i + 1) + 1);
	if (left_over == NULL)
		return (NULL);
	ft_strcpy(left_over, line + i + 1);
	if (*left_over == '\0')
		ft_free(&left_over);
	line[i + 1] = '\0';
	return (left_over);
}

void	ft_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	*get_next_line(int fd)
{
	static char	*rest[4096];
	char		*line;
	char		*temp;
	size_t		remainder_len;

	remainder_len = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp = malloc (BUFFER_SIZE + 1);
	if (!temp)
		return (0);
	line = ft_lets_go(fd, rest[fd], temp, remainder_len);
	ft_free(&temp);
	if (!line)
		ft_free(&rest[fd]);
	if (!line)
		return (NULL);
	rest[fd] = ft_remainder(line);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		counter;

// 	counter = 0;
// 	fd = open("textfile1.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%d:", counter++);
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);

// 	return (0);
// }
