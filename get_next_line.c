/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jou <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:50:36 by jou               #+#    #+#             */
/*   Updated: 2024/01/12 05:29:01 by jou              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int	i;
	int	i2;
	int	j_len;
	char	*join;

	j_len = ft_strlen(s1) + ft_strlen(s2);
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
	if (!join[0])
	{
		free(join);
		return (NULL);
	}
	free (s1);
	return (join);
}

char	*get_rest(char *next_line)
{
	int	i;
	int	i2;
	int	len;
	char	*rest;
	
	i = 0;
	while (next_line && next_line[i] && next_line[i] != '\n')
		i++;
	if (!next_line[i])
	{
		free (next_line);
		return (NULL);
	}
	if (next_line && next_line[i] == '\n')
		i++;
	rest = (char *) malloc(ft_strlen(next_line) - i + 1 * sizeof(char));
	if (!rest)
		return (NULL);
	i2 = 0;
	len = ft_strlen(next_line) - i;
	while (next_line && i2 < len)
	{
		rest[i2] = next_line[i];
		i2++;
		i++;
	}
	rest[i2] = '\0';
	if (next_line)
		free(next_line);
	return (rest);
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
		{
			i++;
			break ;
		}
		i++;
	}
	line = (char *) malloc(i + 1 * sizeof(char));
	if (!line)
		return (NULL);
	i2 = 0;
	while (next_line && i2 < i)
	{
		line[i2] = next_line[i2];
		i2++;
	}
	line[i2] = '\0';
	return (line);
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
			free (buf);
			return (NULL);
		}
		buf[bytes] = '\0';
		next_line = ft_strjoin(next_line, buf);
	}
	free (buf);
	if (!next_line)
		return (NULL);
	line = get_line(next_line);
	next_line = get_rest(next_line);
	return (line);
}


#include <fcntl.h>
#include <stdio.h>
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
