/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:48:45 by jgils             #+#    #+#             */
/*   Updated: 2024/01/13 17:40:31 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*calloc;
	size_t	i;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	calloc = malloc(nmemb * size);
	if (!calloc)
		return (NULL);
	i = 0;
	while (i < size)
	{
		((char *) calloc)[i] = 0;
		i++;
	}
	return (calloc);
}

int	is_line(char *next_line)
{
	int		i;

	i = 0;
	if (!next_line)
		return (0);
	while (next_line[i])
	{
		if (next_line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
