/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:18:44 by jgils             #+#    #+#             */
/*   Updated: 2023/11/29 04:15:35 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //read
#include <stdio.h> //printf
#include <stdlib.h> //malloc
#include <fcntl.h> //open
#include "libft.h" //buffersize ft_strlen ft_strlen

#BUFFER_SIZE = 42;

int	get_end(static char *str)
{
	int		i;

	i = 0;
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
/*
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
*/
char	*new_size(char *str, size_t size)
{
	int	i;
	char    *newstr;

        i = 0;
        if (buf[0] == '\n')
                i++;
        newstr = (char *) malloc ((size - i) + sizeof(ft_strlen(str)));
        if (!newstr)
                newstr = NULL;
        free (str);
        return (newstr);
}

char	*keep(str, buf, size)
{

}

// ideia: dividir em: primeira rodada/ resto das rodadas

int	main(void)
{
	char	*buf;
	static char	*temp;
	char	*str;
	size_t	end;
	int	file;

	file = open("test.txt", O_RDONLY);
	buf = (char *) malloc (BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (NULL);
	while (read(file, buf, BUFFER_SIZE) >= 0)
	{
		end = get_end(buf);
		if (buf[end] == '\n')
			end++;
		if ((end >= 1) && (end < BUFFER_SIZE))
		{
			temp = (char *) new_size((BUFFER_SIZE - (end + 2) * sizeof(char)));
			ft_strlcpy(temp, &buf[end + 2], (BUFFER_SIZE - (end + 2)));
		}
		str = new_size(str, (end * sizeof(char)));
		str = ft_strjoin(str, buf, end);
	}
	free(buf);
	return (str);
	printf("%s", buf);
}
