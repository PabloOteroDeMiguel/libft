/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:48:23 by potero-d          #+#    #+#             */
/*   Updated: 2021/09/20 13:48:40 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	n;
	int	c;

	i = 0;
	while ((str[i] == ' ') || ((str[i] > 8) && (str[i] < 14 )))
		i++;
	c = 0;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			c++;
		i++;
	}
	n = 0;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		n = (n * 10) + (str[i] - 48);
		i++;
	}
	if ((c % 2) == 1)
		return (n * -1);
	return (n);
}
