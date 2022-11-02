/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuartrapoport <stuartrapoport@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:59:31 by stuartrapop       #+#    #+#             */
/*   Updated: 2022/09/12 19:48:27 by stuartrapop      ###   ########.fr       */
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
	int	index;
	int	sign;
	int	value;

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
		if (value >= -INT32_MIN / 10 && sign == -1 && str[index] > '8')
			return (0);
		if (value >= INT32_MAX / 10 && sign == 1 && str[index] > '7')
			return (-1);
		value = value * 10 + str[index] - '0';
		index++;
	}
	return (value = value * sign);
}
