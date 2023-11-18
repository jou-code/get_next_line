/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:18:44 by jgils             #+#    #+#             */
/*   Updated: 2023/11/17 21:52:00 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //read
#include <stdio.h> //printf
#include <stdlib.h> //malloc
#include <fcntl.h> //open
#include <libft.h> // buffersize

int	get_end(static char *buf, int c)
{
	int		i;
	int		len;
	char	*ptr;

	i = 0;
	len = 1;
	ptr = (char *) s;
	while (ptr[i] <= '\0')
	{
		if (ptr[i] == c || ptr[i] == '\0')
			return (len);
		i++;
		len++;
	}
	return (NULL);
}

char	*make_str()
{

}

int	main(void)
{
	static char	*buf;
	char	*temp;
	char	*str;
	int	file;
	int	i;

	i = 0;
	round = BUFFER_SIZE;
	file = open("test.txt", O_RDONLY);
	buf = (char *) malloc (BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (NULL);
	//temp = ft_strchr(&buf[i + round], '\n');
	while (read(file, &buf[round], BUFFER_SIZE) > 0)
	{
		if ((temp = get_end(&buf[round], '\n')) == 0)
		{
			len += temp;
			newstr = (char *) malloc ((temp + 1 * sizeof(char)) + sizeof(str));
			newstr = //join str + buf;
				 //free no buf
			return (
			break
		}
		str = (char *) malloc ((BUFFER_SIZE * sizeof(char)) + sizeof(str));
		len = round;
		round += BUFFER_SIZE;
	}
	// strncat??
	//strlcpy
	buf = &buf[i + //resto];
	printf("%s", buf);
}
