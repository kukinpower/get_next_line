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
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char		*ft_strdup(const char *s1)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (!(str = malloc(len + 1)))
		return (NULL);
	while (len--)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_strchr(const char *s, int c)
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

char		*ft_strjoin_upg(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	char	*save;

	len = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		len = ft_strlen(s2) + 1;
	else if (s1 && s2)
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(str = malloc(sizeof(*str) * (len))))
		return (NULL);
	save = str;
	if (s1)
		while (*s1)
			*str++ = *s1++;
	if (s2)
		while (*s2)
			*str++ = *s2++;
	*str = 0;
	return (save);
}
