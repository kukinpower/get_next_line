/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 06:44:21 by mkristie          #+#    #+#             */
/*   Updated: 2020/06/13 06:44:22 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*str1;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	if (!(str1 = malloc(len + 1)))
		return (NULL);
	while (i < len)
	{
		str1[i] = s1[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	int		i;
	char	*str;

	ch = (char)c;
	i = 0;
	str = (char *)s;
	if (c == '\0')
		return (str + ft_strlen(s));
	while (str[i])
	{
		if (str[i] == ch)
			return (str + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	lens1;
	size_t	lens2;
	size_t 	i;
	size_t 	j;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		lens1 = ft_strlen(s1);
		lens2 = ft_strlen(s2) + 1;
		if (!(str = malloc(sizeof(*str) * (lens1 + lens2))))
			return (NULL);
		while (i < lens1)
		{
			str[i] = (char *)s1[i];
			i++;
		}
		while (j < lens2)
		{
			str[i + j] = (char *)s1[j];
			j++;
		}
		str[i + j] = 0;
		return (str);
	}
	return (NULL);
}
