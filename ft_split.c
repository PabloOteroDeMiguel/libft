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
	if ((c == '\0') || (ft_strlen(s) == 0))
		return (0);
	if (s[i] == c)
	{
		while (s[i] == c)
			i++;
		if (i == (ft_strlen(s) - 1))
			return (0);
	}
	else
	{
		w = 1;
		while (i < (ft_strlen(s) - 1))
		{
			if ((s[i] == c) && (s[i - 1] != c))
				w++;
			i++;
		}
		if (s[i] == c && s[i - 1] == c && w > 0 && ft_strlen(s) > 0)
			w = w - 1;
	}
	return (w);
}

static size_t	ft_wlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while ((s[i] != c) && (i < (ft_strlen(s) - 1)))
		i++;
	return (i);
}

static int	ft_rmvc(char const *s, char c)
{
	size_t	i;

	i = 0;
	while ((s[i] == c) && (i < (ft_strlen(s) - 1)))
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int					w;
	unsigned int		i;
	int					j;
	char				**str;

	i = 0;
	if (!s)
		return (0);
	if (s[i] == c)
		i = ft_rmvc(s, c);
	w = ft_word(&s[i], c);
	str = malloc(sizeof(char *) * (w + 1));
	if (!str)
		return (0);
	j = 0;
	if (ft_strlen(s) - 1 == ft_wlen(&s[i], c))
	{
		str[j] = ft_strdup(s);
		j++;
	}
	while (j < w)
	{
		str[j] = ft_substr(s, i, (ft_wlen(&s[i], c) + 1));
		if ((str[j][(ft_strlen(str[j]) - 1)]) == c)
			str[j] = ft_substr(str[j], 0, (ft_strlen(str[j]) - 1));
		i = i + (ft_wlen(&s[i], c) + (ft_rmvc(&s[i + (ft_wlen(&s[i], c))], c)));
		j++;
	}
	str[j] = 0;
	return (str);
}