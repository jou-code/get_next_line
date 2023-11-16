# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgils <jgils@student.42.rio>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 10:50:23 by jgils             #+#    #+#              #
#    Updated: 2023/11/16 11:39:01 by jgils            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS= -Wall -Werror -Wextra
SRC= get_next_line.c get_next_line_utils.c get_next_line.h
TEST_FILES= *.txt

test $(NB): $(SRC)
	cc $(FLAGS) main.c $(SRC) $(NB).txt

tester :
	cd ../pasta
	comando
	cd ../get_next_line

finish :
	rm -rf $(TEST_FILES) main.c
