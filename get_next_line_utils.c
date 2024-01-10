/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:48:45 by jgils             #+#    #+#             */
/*   Updated: 2024/01/10 11:51:16 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *s)
{
	int		i;
	char	*dest;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	dest = (char *) malloc((i + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

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
	return (dest);
}

int	ft_strlen(char *s)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!s)
		return (0);
	while (s && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		is2;

	i = 0;
	is2 = 0;
	newstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (!newstr)
		return (NULL);
	while (s1 && s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2 && s2[is2])
	{
		newstr[i] = s2[is2];
		s2++;
		i++;
	}
	newstr[i + is2] = '\0';
	if (s1)
		free (s1);
	return (newstr);
}
