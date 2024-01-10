/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jou <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:50:36 by jou               #+#    #+#             */
/*   Updated: 2024/01/10 10:29:56 by jgils            ###   ########.fr       */
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
newstr			i++;
			break ;
		}
		i++;
	}
	return (i);
}

char	*get_str(char *s1, char **s2, int flag)
{
	char	*str;
	int		len;

	len = get_end(s1);
	if (!*s2)
	if (!s1 || !len)
		return (NULL);
	if (s1[len] && s1[len - 1] == '\n')
	{
		//free (*s2);
		*s2 = ft_strdup(&s1[len]);
	}
	else
		*s2 = 0;
	str = ft_strndup(s1, len, flag);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*keep;
	int			bytes;
	char		*buf;
	char		*str;
	char		*newstr;

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
		str = get_str(keep, &keep, 1);
	bytes = 1;
	while ((str[get_end(str) - 1] != '\n') && (bytes > 0))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		buf[bytes] = '\0';
		newstr = get_str(buf, &keep, 0);
		str = ft_strjoin(str, newstr);
	}
	free (buf);
	if (str[0] == 0)
		return (NULL);
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
