/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 06:44:13 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/13 08:37:03 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** If any error or mem was not allocated:	return (-1)
** If all went good and EOF:				return (0)
** If all went good and not EOF:			return (1)
*/

#include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include <stdio.h>
//# include "libft/libft.h"

static _Bool	check_input(int fd, char **buf, char **line, _Bool *click)
{
	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	if (!(*buf = malloc(BUFFER_SIZE + 1)))
		return (0);
	if (!(*line = ft_strdup("")))
		return (0);
	*click = 1;
	return (1);
}

static int		free_and_errors(int exit_code, char **buf, char **remember)
{
	if (*buf)
		free(*buf);
	if (*remember && exit_code == -1)
		free(*remember);
//	if (*line)
//		free(*line);
	return (exit_code);
}

static _Bool	check_remember(char **remember, char **line)
{
	if (*remember)
	{
		if (!(*line = ft_strjoin_upg(*line, *remember)))
			return (0);
		free(*remember);
		*remember = NULL;
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	int 		bytes_read;
	char 		*newline_pointer;
	char		*temp;
	_Bool 		click;
	static char	*remember;

	if (!line || !(check_input(fd, &buf, line, &click)))
		return (-1);
	if (!(check_remember(&remember, line)))
		return(free_and_errors(-1, &buf, &remember));
	while (click && (bytes_read = read(fd, buf, BUFFER_SIZE)))
	{
		if (bytes_read < 0)
			return(free_and_errors(-1, &buf, &remember));
		buf[bytes_read] = '\0';
		if ((newline_pointer = ft_strchr(buf, '\n')))
		{
			*newline_pointer = '\0';
			click = 0;
			if (!(remember = ft_strdup(++newline_pointer)))
				return(free_and_errors(1, &buf, &remember));
		}
		temp = *line;
		if(!(*line = ft_strjoin_upg(temp, buf)))
			return (-1);
		free(temp); // ?
		temp = NULL;
	}
//	if (temp)
//		free(temp);
	if (click == 0)
		return (free_and_errors(1, &buf, &remember));
	return (free_and_errors(0, &buf, &remember));
}
