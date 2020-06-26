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

static _Bool	append_utils(char **append_this, char **remainder, \
								char **line, char **newline_ptr_temp)
{
	char		*temp;

	if (!(*append_this = ft_substr(*remainder, 0, \
		ft_strlen(*remainder) - ft_strlen(*newline_ptr_temp))))
	{
		free(*remainder);
		return (0);
	}
	if (!(temp = ft_strdup((*newline_ptr_temp) + 1)))
	{
		free(*remainder);
		return (0);
	}
	free(*remainder);
	*remainder = temp;
	temp = NULL;
	if (!(*line = ft_strjoin_upg(*line, *append_this)))
	{
		free(*append_this);
		return (0);
	}
	free(*append_this);
	*append_this = NULL;
	return (1);
}

static _Bool	append(char **remainder, char **line, _Bool *flag)
{
	char		*newline_ptr_temp;
	char		*append_this;

	if (*remainder)
	{
		if ((newline_ptr_temp = ft_strchr(*remainder, '\n')))
		{
			if (!(append_utils(&append_this, remainder, \
								line, &newline_ptr_temp)))
				return (0);
			*flag = 0;
		}
		else
		{
			if (!(*line = ft_strjoin_upg(*line, *remainder)))
			{
				free(*remainder);
				return (0);
			}
			free(*remainder);
			*remainder = NULL;
		}
	}
	return (1);
}

static _Bool	check_input(int fd, char **line, _Bool *flag, char **remainder)
{
	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	if (!(*line = ft_strdup("")))
		return (0);
	*flag = 1;
	if (*remainder && !(append(remainder, line, flag)))
		return (0);
	return (1);
}

static _Bool	append_remainder(char **remainder, char **newline_pointer)
{
	char		*temp;

	(*newline_pointer)++;
	if (*remainder)
	{
		temp = *remainder;
		if (!(*remainder = ft_strjoin_upg(*remainder, *newline_pointer)))
		{
			free(temp);
			return (0);
		}
		free(temp);
		temp = NULL;
	}
	else
	{
		if (!(*remainder = ft_strdup(*newline_pointer)))
			return (0);
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	*remainder;
	char		buf[BUFFER_SIZE + 1];
	char		*newline_pointer;
	_Bool		flag;
	int			bytes_read;

	if (!line || (read(fd, buf, 0) < 0) || \
		!(check_input(fd, line, &flag, &remainder)))
		return (-1);
	while (flag && (bytes_read = read(fd, buf, BUFFER_SIZE)))
	{
		if (bytes_read < 0)
			return (-1);
		buf[bytes_read] = 0;
		if ((newline_pointer = ft_strchr(buf, '\n')))
		{
			*newline_pointer = '\0';
			flag = 0;
			if (!(append_remainder(&remainder, &newline_pointer)))
				return (-1);
		}
		if (!(*line = ft_strjoin_upg(*line, buf)))
			return (-1);
	}
	return ((!flag) ? 1 : 0);
}
