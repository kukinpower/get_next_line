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

//#include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include <stdio.h>
# include "libft/libft.h"


int		get_next_line(int fd, char **line)
{
	char	buf[BUFFER_SIZE + 1];
	int 	bytes_red;
	char 	*newline_pointer;
	int 	click;
	static char	*remember;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (-1);
	if (remember)
		*line = ft_strdup(remember);
	else
		*line = ft_strdup("");
	click = 1;
	while (click && (bytes_red = read(fd, buf, 10)))
	{
		buf[bytes_red] = '\0';
		if ((newline_pointer = ft_strchr(buf, '\n')))
		{
			*newline_pointer = '\0';
			click = 0;
			remember = ft_strdup(++newline_pointer);
		}
		*line = ft_strjoin_free(*line, buf, 0);
	}
	return (0);
}

int		main()
{
	char	*line;
	int 	fd;

	fd = open("/Users/romankukin/development/21/get_next_line/text.txt", O_RDONLY);
	printf("[fd: %d]\n", fd);
	printf("[BUFFER_SIZE: %d]\n", BUFFER_SIZE);
	line = "Hello!";
	while((get_next_line(fd, &line)))
		printf("%s\n", line);
}

//int main(void)
//{
////	char *line;
//	int  fd;
//
//	fd = open("/Users/romankukin/development/21/get_next_line/text.txt", O_RDONLY);
//	printf("%d\n", fd);
//}