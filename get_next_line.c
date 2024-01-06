/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jou <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:50:36 by jou               #+#    #+#             */
/*   Updated: 2024/01/06 00:06:39 by jou              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf
#include <unistd.h> // write?
//#include <limits.h> //
#include <stdlib.h> //malloc NULL
#include <fcntl.h> //open

# define BUFFER_SIZE 42

size_t  ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char    *ft_strndup(const char *s, int n);
char    *ft_strjoin(char const *s1, char const *s2);

int     get_end(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
                if (str[i] == '\n')
		{
			i++;
			break ;
		}
                i++;
        }
        return (i);
}

char	*get_str(char *buf, char **keep)
{
	char	*str;
	int	len;

	len = get_end(buf);
	if (!buf || !len)
		return (NULL);
	else if (buf[0] == '\n')
		str = "\n";
	else
		str = ft_strndup(buf, len);
	


	if (len > 1 && str[len - 1] == '\n')
		str[len - 1] = '\0';

	if (buf[len] && buf[len - 1] == '\n')
		*keep = ft_strdup(&buf[len]);

	return (str);

}


char	*get_next_line(int fd)
{
	char	*str;


	return (str);
}

int     main(void)
{
	int     fd;

        fd = open("test.txt", O_RDONLY);
        printf("%s", get_next_line(fd));
        return (0);
}

/*
int	main(teste get_str)
{
	static char	*keep;
	char	*buf;

	buf = "";
	keep = "teste";

	printf("str-----\n%s\n", get_str(buf, &keep));
	printf("keep-----\n%s\n", keep);
}
*/
