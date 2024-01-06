/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 06:46:10 by jgils             #+#    #+#             */
/*   Updated: 2023/12/13 15:07:56 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strndup(char *s, int n)
{
	int		i;
	char	*dest;

	i = 0;
	if (!s || !n)
		return (NULL);
	dest = (char *) malloc((n + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (i < n)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	//free (s);
	return (dest);
}
