/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jou <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:50:36 by jou               #+#    #+#             */
/*   Updated: 2024/01/11 23:53:49 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf
#include <unistd.h> // write?
#include <stdlib.h> //malloc NULL
#include <fcntl.h> //open
#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int	i;
	int	i2;
	int	j_len;
	char	*join;

	j_len = 0;
	while (s1 && s1[j_len])
		j_len++;
	while (s2 && s2[j_len])
		j_len++;
	join = (char *) malloc(j_len + 1 * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	i2 = 0;
	while (s1 && s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2 && s2[i2])
		join[i++] = s2[i2++];
	join[i] = '\0';
	return (join);
}

int	is_line(char *next_line)
{
	int		i;

	i = 0;
	while (next_line && next_line[i])
	{
		if (next_line[i] == '\n')
			return (1);
		i++;
	}
	return(0);
}

char	*get_line(char *next_line)
{
	int	i;
	int	i2;
	char	*line;

	i = 0;
	while (next_line && next_line[i])
	{
		if (next_line[i] == '\n')
			break ;
		i++;
	}
	if (next_line[0] == '\n')
		i++;
	line = (char *) malloc(i + 1 * sizeof(char));
	if (!line)
		return (NULL);
	i2 = 0;
	while (i2 < i)
	{
		line[i2] = next_line[i2];
		i2++;
	}
	line[i2] = '\0';
	return (line);
}

char	*get_rest(char *next_line)
{
	int	i;
	int	i2;
	int	nl_len;
	char	*rest;

	i = 0;
	while (next_line && next_line[i] != '\n')
		i++;
	i++;
	if (!(i + 1))
	{
		free(next_line);
		return (NULL);
	}
	nl_len = 0;
	while (next_line && next_line[nl_len])
		nl_len++;
	rest = (char *) malloc(nl_len - i + 1 * sizeof(char));
	i2 = 0;
	while (i <= nl_len)
		rest[i2++] = next_line[i++];
	rest[i2] = '\0';
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*next_line;
	char	*line;
	char	*buf;
	int	bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *) malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buf)
		return(NULL);
	bytes = 1;
	while (!is_line(buf) && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes] = '\0';
		next_line = ft_strjoin(next_line, buf);
	}
	free(buf);
	line = get_line(next_line);
	next_line = get_rest(next_line);
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
