/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:45:56 by jou               #+#    #+#             */
/*   Updated: 2023/12/14 22:27:42 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>

static size_t  ft_strlen(const char *s)
{
        int     i;
	int	len;

        i = 0;
	len = 0;
	if (!s)
		return (0);
        while (s[i])
	{
		len++;
                i++;
	}
        return (len);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		is2;

	i = 0;
	is2 = 0;
	newstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) * sizeof(char));
	if (!newstr)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			newstr[i] = s1[i];
			i++;
		}
	}

	while (s2[is2] && s2[is2])
	{
		newstr[i] = s2[is2];
		s2++;
		i++;
	}
	return (newstr);
}
