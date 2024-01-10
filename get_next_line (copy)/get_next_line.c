/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jou <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:50:36 by jou               #+#    #+#             */
/*   Updated: 2024/01/10 18:07:00 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf
#include <unistd.h> // write?
#include <stdlib.h> //malloc NULL
#include <fcntl.h> //open
#include "get_next_line.h"

int	is_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (0);
}

char	*get_line(char *line, char *buf)
{
	int	i;
	int	i2;
	char	*newline;

	i = 0;
	while (buf[i])
		i++;
	while (line && line[i])
		i++;
	newline = (char *) malloc((i + 1) * sizeof(char));
	i = 0;
	i2 = 0;
	while (line && line[i])
		newline[i2++] = line[i++];
	while (buf[i])
		newline[i2++] = buf[i++];
	newline[i2] = '\0';
	if (line)
		free(line);
	return (newline);
}

char	*get_static(char *line)
{
	int		i;
	int		i2;
	char	*next_line;

	i = is_line(line);
	if (!i)
		return (NULL);
	next_line = (char *) malloc((BUFFER_SIZE - i + 1) * sizeof(char));
	i2 = 0;
	while (line[i])
		next_line[i2++] = line[i++];
	next_line[i2] = '\0';
	return (next_line);
}

char	*get_next_line(int fd)
{
	int		bytes;
	char	*line;
	char	*buf;
	static char	*next_line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	line = (char *) malloc(sizeof(char));
	line[0] = '\0';
	if (next_line)
		line = get_line(line, next_line);
	bytes = 1;
	while (!is_line(line) && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		buf[bytes] = '\0';
		if (bytes <= 0)
		{
			free(buf);
			return (NULL);
		}
		next_line = get_line(line, buf);
	}
	if (next_line)
		free(next_line);
	line = get_line(line, buf);
	next_line = get_static(line);
	free(buf);
	return (line);
}

int     main(void)
{
	int     fd;
	char	*gnl;

        fd = open("1-brouette.txt", O_RDONLY);
	gnl = get_next_line(fd);
	while (gnl)
	{
		printf("%s", gnl);
		free (gnl);
		gnl = get_next_line(fd);
	}
	free (gnl);
        return (0);
}
/*
int	main(teste get_str)
{
	static char	*keep;
	char	*buf;

	buf = "";
	keep = "teste";

	printf("str-----\n%s\n", get_str(buf, &keep));
	printf("keep-----\n%s\n", keep);
}
*/
