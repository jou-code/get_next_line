/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgils <jgils@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:42:46 by jgils             #+#    #+#             */
/*   Updated: 2024/01/08 18:17:42 by jou              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char    *ft_strdup(char *s);
char    *ft_strndup(char *s, int n);
char    *ft_strjoin(char *s1, char *s2);
int     get_end(char *str);
char    *get_str(char *buf, char **keep);

#endif
