/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:18:59 by jgils             #+#    #+#             */
/*   Updated: 2023/11/16 14:59:09 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <limit.h> //NULL

char	*makestr(int fd)
{
	char	*buf;
	char	*str;
	int	i;
	int	s;

	i = 0;
	s = 0;
	buf = (char *) malloc (BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (NULL);
	read(fd, buf, BUFFER_SIZE);
	while (buf[i] && buf[i] != '\n')
	{
		str = (char *) malloc (sizeof(char));
		if (!str)
			return (NULL);
		buf[i] = str[s + i];
		i++;
	}
	if (str[s + i] == '\n')
		str[s + i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static int	count;

	count = 0;
	return (str);
}

int	main(void)
{
	
