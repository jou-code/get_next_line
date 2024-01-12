/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:48:45 by jgils             #+#    #+#             */
/*   Updated: 2024/01/12 05:14:51 by jou              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return(i);
}

int	is_line(char *next_line)
{
	int		i;

	i = 0;
	while (next_line && next_line[i])
	{
		if (next_line[i] == '\n')
			return (1);
		i++;
	}
	return(0);
}

