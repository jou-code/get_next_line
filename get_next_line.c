/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jou <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:50:36 by jou               #+#    #+#             */
/*   Updated: 2024/01/09 02:08:57 by jgils            ###   ########.fr       */
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
	while (str && str[i])
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

char	*get_str(char *buf, char **keep)
{
	char	*str;
	int		len;

	len = get_end(buf);
	if (!buf || !len)
		return (NULL);
	if (buf[len] && buf[len - 1] == '\n')
		*keep = ft_strdup(&buf[len]);
	else
		a*keep = 0;
	str = ft_strndup(buf, len);
	return (str);
}

char	acumulate_str()
{

}

char	*get_next_line(int fd)
{
	static char	*keep;
	int			bytes;
	char		*buf;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *) malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	str = (char *) malloc (sizeof(char));
	str[0] = 0;
	if (!str)
		return (NULL);
	if (keep)
		str = get_str(keep, &keep);
	bytes = 1;
	while ((str[get_end(str) - 1] != '\n') && (bytes > 0))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			return (NULL);
		}	
		buf[bytes] = '\0';
		str = ft_strjoin(str, get_str(buf, &keep));
	}
	free (buf);
	if (str[0] == 0)
		return (NULL);
	return (str);
}
/*
int     main(void)
{
	int     fd;
	char	*gnl;

        fd = open("1-brouette.txt", O_RDONLY);
	gnl = get_next_line(fd);
	while (gnl)
	{
		printf("%s", gnl);
		gnl = get_next_line(fd);
	}
        return (0);
}

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
