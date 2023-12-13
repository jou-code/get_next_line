/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:18:59 by jgils             #+#    #+#             */
/*   Updated: 2023/12/13 11:32:00 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf
#include <unistd.h> // write?
#include <limits.h> //NULL
#include <stdlib.h> //malloc
#include <fcntl.h> //open

# define BUFFER_SIZE 42

size_t	ft_strlen(const char *s);
char	*ft_strndup(const char *s, int n);
char	*ft_strnjoin(char const *s1, char const *s2, int n);

char	*add_null(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	while (str[i])
		i++;
	dest = (char *) malloc((i + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	free(str);
	return (dest);
}

char	*makestr_keeprest(char *str, char *buf, char *keep)
{	
	//char	*str;
	int	len;

	//str = 0;
	if (buf[0] == '\n')
		return ("\n");
	len = ft_strlen(buf);
	if (!str)
		str = ft_strndup(buf, len);
	else
		ft_strnjoin(str, buf, len);
	if (buf[len] == '\n')
	{
		keep = ft_strndup(&buf[len + 1], ft_strlen(&buf[len + 1]));
		add_null(str);
	}
	return (str);
}


char	*get_next_line(int fd)
{
	char	*buf;
	char	*str;
	static char	*keep;
	int	len;
	int	add;

	str = 0;
	keep = 0;
	add = 0;
	buf = (char *) malloc (BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (NULL);
	if (keep)
	{
		if (keep[0] == '\n')
			return ("\n");
		len = ft_strlen(keep);
		str = ft_strndup(keep, len);
		if (keep[len] == '\n')
		{	
			add++;
			keep = ft_strndup(&buf[len + 1], ft_strlen(&buf[len + 1]));
		}
	}
	while ((buf[len] != '\n') && (read(fd, buf, BUFFER_SIZE) >= 0) && !add)
			makestr_keeprest(str, buf, keep);
	if (buf[len] == '\n' || add)
		add_null(str);
	free(buf);
	return (str);
}
/*
char	*get_next_line(int fd)
{
	static int	count;

	count = 0;
	return (str);
}
*/
int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("str: %s", get_next_line(fd));
	return (0);
}
