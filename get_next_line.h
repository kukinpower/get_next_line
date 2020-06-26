/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 06:44:16 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/19 19:27:00 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include <stdio.h>


int							get_next_line(int fd, char **line);
size_t 						ft_strlen(const char *s);
char						*ft_strdup(const char *s1);
char						*ft_strchr(const char *s, int c);
char						*ft_strjoin_upg(char const *s1, char const *s2);
char						*ft_substr(char const *s, unsigned int start, size_t len);

#endif