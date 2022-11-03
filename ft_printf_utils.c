/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:54:07 by srapopor          #+#    #+#             */
/*   Updated: 2022/10/20 16:38:19 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_putchr(char c, int *count)
{
	int	write_value;

	write_value = write(1, &c, 1);
	if (write_value == -1)
		*count = -1;
	else
		*count += write_value;
}

void	ft_putnbr_hex(unsigned int n, char format, int *letter_count)
{
	char			c;
	long long int	internal_n;

		internal_n = (long long int)n;
	if (internal_n < 0)
	{
		*letter_count += write(1, "-", 1);
		internal_n = -internal_n;
	}
	c = internal_n % 16;
	if (c < 10)
		c = c + '0';
	else
	{
		if (format == 'x')
			c = c - 10 + 'a';
		else
			c = c - 10 + 'A';
	}
	if (internal_n / 16)
		ft_putnbr_hex(internal_n / 16, format, letter_count);
	*letter_count += write(1, &c, 1);
}

void	ft_putnbr_unsigned(unsigned int n, int *letter_count)
{
	char			c;

	c = n % 10 + '0';
	if (n / 10)
		ft_putnbr_unsigned (n / 10, letter_count);
	*letter_count += write(1, &c, 1);
}

void	ft_put_address(unsigned long n, int *letter_count)
{
	char	c;

	c = (int)(n % 16);
	if (c < 10)
		c = c + '0';
	else
		c = c - 10 + 'a';
	if (n / 16)
		ft_put_address((unsigned long)(n / 16), letter_count);
	*letter_count += write(1, &c, 1);
}
