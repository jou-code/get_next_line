/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:18:59 by jgils             #+#    #+#             */
/*   Updated: 2023/12/14 12:23:37 by jgils            ###   ########.fr       */
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
char	*ft_strjoin(char const *s1, char const *s2);

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

char	*get_str(char *buf, char *keep)
{	
	char	*str;
	int	len;

	str = 0;
	len = ft_strlen(buf);
	if (buf[0] == '\n')
		str = "\n";
	else
		str = ft_strndup(buf, len);
	if ((buf[len + 1] != '\0') && (buf[len] == '\n'))
		keep = ft_strndup(&buf[len + 1], ft_strlen(&buf[len + 1])); //tem q copiar \n
	if (buf[len] == '\n')
		add_null(str);
	return (str);
	(void)keep;
}


char	*get_next_line(int fd)
{
	char	*buf;
	char	*str;
	static char	*keep;

	str = 0;
	buf = (char *) malloc (BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (NULL);
	if (keep)
		get_str(keep, keep);
	while ((read(fd, buf, BUFFER_SIZE) > 0) && (buf[ft_strlen(buf)] != '\n'))
		str = ft_strjoin(str, get_str(buf, keep));

	free(buf);
	return (str);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	return (0);
}
