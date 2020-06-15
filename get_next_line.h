/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 06:44:16 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/13 06:55:31 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include <stdio.h>

typedef struct				s_gnl_struct
{
	int 					fd;
	char 					*line;
	struct s_gnl_struct		*next;
}							t_gnl_struct;


int							get_next_line(int fd, char **line);
size_t 						ft_strlen(const char *s);
char						*ft_strdup(const char *s1);
char						*ft_strchr(const char *s, int c);
char						*ft_strjoin(char const *s1, char const *s2);


#endif