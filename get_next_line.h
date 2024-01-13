/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:42:46 by jgils             #+#    #+#             */
/*   Updated: 2024/01/12 15:47:58 by jou              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

#include <unistd.h>
#include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2);
int	ft_strlen(char *str);
char	*get_rest(char *next_line);
char	*get_line(char *next_line);
char	*get_next_line(int fd);
int	is_line(char *next_line);



#endif
