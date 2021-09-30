/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:07:45 by potero-d          #+#    #+#             */
/*   Updated: 2021/09/21 13:22:02 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (len == 1 && start >= ft_strlen(s))
	{
		str = malloc(1);
		if (!str)
			return (0);
		str[0] = '\0';
		return (str);
	}
	else
		str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (start < ft_strlen(s))
	{	
		ft_strlcpy(str, &s[start], len + 1);
	}
	else
		ft_strlcpy(str, "", 1);
	return (str);
}
