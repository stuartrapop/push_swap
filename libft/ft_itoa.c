/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:37:04 by srapopor          #+#    #+#             */
/*   Updated: 2022/09/13 19:15:24 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	ft_number_length(int n)
{
	int					length;
	long long int		temp_number;

	length = 1;
	temp_number = (long long int)n;
	if (temp_number < 0)
		length++;
	while (temp_number / 10)
	{
		temp_number = temp_number / 10;
		length++;
	}
	return (length);
}

static char	ft_get_last_char(int n)
{
	long long int	temp;

	temp = (long long int)n;
	if (n < 0)
		return (-temp % 10 + '0');
	else
		return (temp % 10 + '0');
}

char	*ft_itoa(int n)
{
	int				index;
	char			*number_string;
	int				string_length;

	string_length = ft_number_length(n);
	number_string = malloc(sizeof(char) * (string_length + 1));
	if (!number_string)
		return (NULL);
	if (n < 0)
		number_string[0] = '-';
	index = string_length - 1;
	while (n / 10)
	{
		number_string[index] = ft_get_last_char(n);
		n = n / 10;
		index--;
	}
	number_string[index] = ft_get_last_char(n);
	number_string[string_length] = '\0';
	return (number_string);
}

//int	main(void)
//{
//	printf("%s\n", ft_itoa(-2147483648));
//}
