/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellatr <mbellatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:30:14 by mbellatr          #+#    #+#             */
/*   Updated: 2023/01/02 00:18:52 by mbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *str)
{
	char	*buffer;
	int		r;

	r = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(str, '\n') && r)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			free(str);
			free(buffer);
			return (NULL);
		}
		buffer[r] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*first_line(char *stash)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!ft_strlen(stash))
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		line = malloc(sizeof(char) * (i + 2));
	else
		line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (j <= i && stash[j])
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*second_line(char *stash)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	line = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!line)
	{
		free(stash);
		return (NULL);
	}
	while (stash[i])
		line[j++] = stash[i++];
	line[j] = '\0';
	free(stash);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_line(fd, stash);
	if (!stash)
		return (NULL);
	line = first_line(stash);
	stash = second_line(stash);
	return (line);
}
