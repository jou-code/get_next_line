/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:42:46 by jgils             #+#    #+#             */
/*   Updated: 2024/01/09 19:06:41 by jgils            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strdup(char *s);
char	*ft_strndup(char *s, int n, int flag);
char	*ft_strjoin(char *s1, char *s2);
char	*get_str(char *buf, char **keep, int flag);
int		get_end(char *str);

#endif
