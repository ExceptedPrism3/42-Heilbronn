/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:35:31 by aben-cad          #+#    #+#             */
/*   Updated: 2025/11/13 21:40:42 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_in_loop(int fd, char *remainder, char *buff)
{
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(remainder), NULL);
		if (bytes_read == 0)
			break ;
		buff[bytes_read] = '\0';
		remainder = ft_strjoin_gnl(remainder, buff);
		if (!remainder)
			return (NULL);
		if (ft_strchr_bonus(buff, '\n'))
			break ;
	}
	return (remainder);
}

static char	*read_join(int fd, char *remainder)
{
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
	{
		free(remainder);
		return (NULL);
	}
	remainder = read_in_loop(fd, remainder, buff);
	free(buff);
	return (remainder);
}

static char	*extract_line_bonus(char *remainder)
{
	char	*line;
	size_t	i;

	if (!remainder || remainder[0] == '\0')
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\n')
		i++;
	line = ft_substr_bonus(remainder, 0, i);
	return (line);
}

static char	*update_remainder(char *remainder)
{
	char	*new_remainder;
	size_t	i;

	if (!remainder)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\0')
	{
		free(remainder);
		return (NULL);
	}
	new_remainder = ft_strdup_bonus(remainder + i + 1);
	free(remainder);
	return (new_remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder[MAX_FD];
	char		*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	remainder[fd] = read_join(fd, remainder[fd]);
	if (!remainder[fd])
		return (NULL);
	line = extract_line_bonus(remainder[fd]);
	if (!line)
	{
		free(remainder[fd]);
		remainder[fd] = NULL;
		return (NULL);
	}
	remainder[fd] = update_remainder(remainder[fd]);
	return (line);
}
