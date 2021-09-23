/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:49:05 by potero-d          #+#    #+#             */
/*   Updated: 2021/09/23 15:53:09 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_start(char const *s1, char const *set)
{
	int	i;
	
	i = 0;
	while(ft_strchr(set, s1[i]))
		i++;
	return (i);
}

int	ft_end(char const *s1, char const *set)
{
	int	i;
	
	i = 0;
	while(ft_strrchr(set, s1[i]))
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
//	int		j;
	int		n;
	int		m;
	char	*str;
	
	if (!s1 || !set)
		return (0);
	if (ft_strlen(s1) == 0 || ft_strlen(set) == 0)
	{
		str = ft_strdup(s1);
		return (str);
	}
	n = ft_start(s1, set);
	m  = ft_end(s1, set);
	i = (ft_strlen(s1) - n - m);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
/*	j = 0;
	while (j < i)
	{
		str[j] = s1[n];
		j++;
		n++;
	}*/
	ft_strlcpy(str, &s1[n], i + 1);
	return (str);
}

