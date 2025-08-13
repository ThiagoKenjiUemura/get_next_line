/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiagouemura <thiagouemura@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:25:32 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/08/13 18:07:31 by thiagouemur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char **remainder)
{
	char	*line;
	int		i;
	char	*tmp;

	if (!(*remainder))
		return (NULL);
	i = 0;
	if (ft_strchr(*remainder, '\n'))
	{
		while ((*remainder)[i] != '\n')
			i++;
		line = ft_substr(*remainder, 0, i + 1);
		tmp = ft_strdup(*remainder + i + 1);
		free(*remainder);
		*remainder = tmp;
		return (line);
	}
	line = ft_strdup(*remainder);
	free(*remainder);
	*remainder = NULL;
	return ();
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*tmp;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!remainder)
		remainder = ft_strdup("");
	bytes_read = 1;
	while (!ft_strchr(remainder, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		if (bytes_read == -1)
		{
			free(remainder);
			remainder = NULL;
			return (NULL);
		}
		tmp = ft_strjoin(remainder, buffer);
		free(remainder);
		remainder = tmp;
	}
	return (extract_line(&remainder));
}
