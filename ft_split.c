/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 09:01:32 by potero-d          #+#    #+#             */
/*   Updated: 2021/09/23 14:01:12 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include"libft.h"
#include<stdio.h>

static int	ft_word(char const *s, char c)
{
	unsigned int	i;
	int				w;

	i = 0;
	w = 0;
	if (ft_strlen(s) == 0)
		return (0);
	if (s[i] == c)
	{
		while (s[i] == c)
			i++;
		if (i == (ft_strlen(s) - 1))
			return (0);
	}
	i = 1;
	w = 1;
	while (i < (ft_strlen(s) - 1))
	{
		if ((s[i] == c) && (s[i - 1] != c))
			w++;
		i++;
	}
	if (s[i] == c && s[i - 1] == c && w > 0 && ft_strlen(s) > 0)
		w = w - 1;
	return (w);
}

static size_t	wo(char const *s, char c)
{
	size_t	i;

	i = 0;
	while ((s[i] != c) && (i < (ft_strlen(s))))
		i++;
	return (i);
}

static int	ft_r(char const *s, char c)
{
	size_t	i;

	i = 0;
	while ((s[i] == c) && (i < (ft_strlen(s))))
		i++;
	return (i);
}

static char	**ft_nosplit(char const *s)
{
	char	**str;

	str = malloc(sizeof(char *) * 2);
	str[0] = (ft_strdup(s));
	str[1] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	unsigned int		i[3];
	char				**str;

	i[2] = 0;
	if (!s)
		return (0);
	if ((ft_strchr(s, c) == 0) && ft_strlen(s) > 0)
		return (ft_nosplit(s));
	if (s[i[2]] == c)
		i[2] = ft_r(s, c);
	i[0] = ft_word(&s[i[2]], c);
	str = malloc(sizeof(char *) * (i[0] + 1));
	if (!str)
		return (0);
	i[1] = 0;
	while (i[1] < i[0])
	{
		str[i[1]] = ft_substr(s, i[2], (wo(&s[i[2]], c)));
		if ((str[i[1]][(ft_strlen(str[i[1]]) - 1)]) == c)
			str[i[1]] = ft_substr(str[i[1]], 0, (ft_strlen(str[i[1]]) - 1));
		i[2] = i[2] + wo(&s[i[2]], c) + ft_r(&s[i[2] + (wo(&s[i[2]], c))], c);
		i[1]++;
	}
	str[i[1]] = 0;
	return (str);
}
