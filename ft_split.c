/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 09:01:32 by potero-d          #+#    #+#             */
/*   Updated: 2021/09/22 14:19:54 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include"libft.h"
#include<stdio.h>

int	ft_word(char const *s, char c)
{
	unsigned int	i;
	int w;
	i = 0;
	w = 0;
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
		if (s[i - 1] == c && s[i - 2] == c && w > 0)
			w = w - 1;
	}
	return (w);
}

int	ft_wordlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while ((s[i] != c) && (i < (ft_strlen(s) - 1)))
		i++;
	return (i);
}

int	ft_removec(char const *s, char c)
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
	if (s == 0)
		return (0);
	if (s[i] == c)
		i = ft_removec(s, c);
	if (i == (ft_strlen(s) - 1))
		w = 0;
	else
		w = ft_word(&s[i], c);
	str = malloc(sizeof(char *)  * w + 1);
	if (!str)
		return (0);
	j = 0;
	while (j < w)
	{
//			printf("s: %s\n", s);
//			printf("i: %d\n", i);
//			printf("W+1: %d\n", ft_wordlen(&s[i], c) + 1);
		str[j] = ft_substr(s, i, ft_wordlen(&s[i], c) + 1);
//			printf("str: %s\n", str[j]);
//			printf("len: %zu\n", ft_strlen(str[j]));
//			printf("%c\n", str[j][(ft_strlen(str[j])-1)]);
		if ((str[j][(ft_strlen(str[j])-1)]) == c)
			str[j] = ft_substr(str[j], 0, (ft_strlen(str[j])-1));
//			printf("str: %s\n", str[j]);
		i = i + ft_wordlen(&s[i], c);
		i = i + ft_removec(&s[i], c);
		j++;
	}
	str[j] = 0;
	return (str);
}
