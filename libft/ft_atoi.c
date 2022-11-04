/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:59:31 by stuartrapop       #+#    #+#             */
/*   Updated: 2022/11/04 13:11:44 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *str)
{
	int		index;
	int		sign;
	long	value;

	index = 0;
	sign = 1;
	value = 0;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign = -sign;
		index++;
	}
	while (ft_isdigit(str[index]))
	{
		value = value * 10 + str[index] - '0';
		index++;
	}
	return (value = value * sign);
}
