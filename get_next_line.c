/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:18:59 by jgils             #+#    #+#             */
/*   Updated: 2023/11/15 19:10:36 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

int	makestr(int fd)
{
	char	*buf;
	int	i;
	int	s;

	i = 0;
	s = 0;
	read(fd, buf, BUFFER_SIZE);
	while (buf[i] != '\n')
	{
		buf[i] = str[s];
}

char	*get_next_line(int fd)
{
	return (str);
}

int	main(void)
{
	
