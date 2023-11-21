/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:18:44 by jgils             #+#    #+#             */
/*   Updated: 2023/11/21 20:15:30 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //read
#include <stdio.h> //printf
#include <stdlib.h> //malloc
#include <fcntl.h> //open
#include <libft.h> // buffersize

int	get_end(static char *buf)
{
	int		i;
	int		len;
	char	*ptr;

	i = 0;
	ptr = (char *) s;
	while (ptr[i] || ptr[i] != '\n')
	{
		i++;
	}
	return (i);
}

char	*make_str(str, buf, size)
{
	int	i;
	char	*newstr;

	i = 0;
	if (buf[0] == '\n')
		i++;
	newstr = (char *) malloc ((size - i) + sizeof(str));
	if (!newstr)
		newstr = NULL;
	while (join)
	free (str);
	return (newstr);
}

int	main(void)
{
	char	*buf;
	static char	*temp;
	char	*str;
	size_t	len;
	int	file;
	int	i;

	i = 0;
	str = NULL;
	file = open("test.txt", O_RDONLY);
	buf = (char *) malloc (BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (NULL);
	if () //?
		return ();
	while (read(file, buf, BUFFER_SIZE) >= 0)
	{
		len = get_end(buf) + 1;
		if (erros)
			return ();
		else if ((len >= 1) && (len < BUFFER_SIZE)) //pensar se o buffersize for > que o arquivo(read)
		{
			str = make_str(str, buf, (len + 1)); //len ++
			temp = make_str(&buf[len + 2], "", (BUFFER_SIZE - (len + 2));
			break ;
		}
		str = make_str(str, buf, BUFFER_SIZE); //trocar buffer size por len
	}
	free(buf);
	if (str[len] == '\n')
		str[len + 1] = '\0';
	return (str);
	printf("%s", buf);
}
