/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 06:46:10 by jgils             #+#    #+#             */
/*   Updated: 2023/12/13 11:29:22 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strndup(const char *s, int n)
{
	int		i;
	char	*dest;

	i = 0;
	if (!s || !n)
		return (NULL);
	dest = (char *) malloc(n * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (s[i] < n)
	{
		dest[i] = s[i];
		i++;
	}
	return (dest);
}
