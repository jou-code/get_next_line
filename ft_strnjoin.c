/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:45:56 by jou               #+#    #+#             */
/*   Updated: 2023/12/13 09:40:04 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	char	*newstr;
	int		i;
	int		is2;

	i = 0;
	is2 = 0;
	newstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[is2] && s2[is2] < n)
	{
		newstr[i] = s2[is2];
		s2++;
		i++;
	}
	return (newstr);
}
