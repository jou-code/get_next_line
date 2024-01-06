/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:45:56 by jou               #+#    #+#             */
/*   Updated: 2024/01/06 01:32:35 by jou              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int  ft_strlen(char *s)
{
        int     i;
	int	len;

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
	newstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (s1 && s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[is2])
	{
		newstr[i] = s2[is2];
		s2++;
		i++;
	}
	//free (s1);
	//free (s2);
	return (newstr);
}
