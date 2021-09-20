/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 09:22:20 by potero-d          #+#    #+#             */
/*   Updated: 2021/09/20 09:24:34 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<string.h>

size_t	ft_strlen(const char *str);

char	*ft_strnstr(const char *str, const char *nstr, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (nstr[0] == '\0')
		return ((char *)(str));
	while ((i < len) && (str[i] != '\0'))
	{
		if (nstr[j] == str[i])
		{
			j++;
			if (j == ft_strlen(nstr))
				return ((char *)(&str[i - j + 1]));
		}
		else
			j = 0;
		i++;
	}
	return (0);
}
