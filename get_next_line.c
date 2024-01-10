/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jou <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:50:36 by jou               #+#    #+#             */
/*   Updated: 2024/01/10 13:37:06 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf
#include <unistd.h> // write?
#include <stdlib.h> //malloc NULL
#include <fcntl.h> //open
#include "get_next_line.h"

int	get_end(char *str)
{
	int		i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

char	*get_str(char *s1) //nao pode free
{
	char	*str;
	int	len;

	if (!s1)
		return (NULL);
	len = get_end(s1);
	str = ft_strndup(s1, len);
	return (str);
}


char	*get_keep(char *s1, int flag) //nao pode dar free
{
	char	*str;
	int		len;

	if (!s1)
		return (NULL);
	len = get_end(s1);
	if (s1[len] && s1[len - 1] == '\n')
		str = ft_strdup(&s1[len]);
	else
		str = 0;
	if (flag)
		free (s1);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*keep;
	int			bytes;
	char		*buf;
	char		*str;

	buf = 0;
	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	buf = (char *) malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	str = (char *) malloc (sizeof(char));
	str[0] = 0;
	if (!str)
		return (NULL);
	if (keep)
	{
		str = get_str(keep);
		keep = get_keep(keep, 1);
	}
	bytes = 1;
	while ((str[get_end(str) - 1] != '\n') && (bytes > 0))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes] = '\0';
		str = ft_strjoin(str, get_str(buf));
		keep = get_keep(buf, 0);
	}
	free (buf);
	if (bytes == 0)
	{
		free(str);
		return (NULL);
	}
	return (str);
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
