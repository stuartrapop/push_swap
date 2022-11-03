/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:00:48 by srapopor          #+#    #+#             */
/*   Updated: 2022/10/20 16:43:45 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"
#include <unistd.h>
#include "ft_printf.h"

static void	ft_putstr(char *s, int *count)
{
	int	write_value;

	if (s == NULL)
		write_value = write(1, "(null)", 6);
	else
		write_value = write(1, s, ft_strlen(s));
	if (write_value == -1)
		*count = -1;
	else
		*count += write_value;
}

static void	ft_putnbr(int n, int *letter_count)
{
	char			c;
	long long int	internal_n;

	internal_n = (long long int)n;
	if (internal_n < 0)
	{
		*letter_count += write(1, "-", 1);
		internal_n = -internal_n;
	}
	c = internal_n % 10;
	c = c + '0';
	if (internal_n / 10)
		ft_putnbr(internal_n / 10, letter_count);
	*letter_count += write(1, &c, 1);
}

static void	ft_print_arg(const char *format_string, int *count, va_list *list)
{
	char	format;

	format = format_string[1];
	if (format == 's')
		ft_putstr(va_arg(*list, char *), count);
	else if (format == 'c')
		ft_putchr(va_arg(*list, int), count);
	else if (format == 'i' || format == 'd')
		ft_putnbr(va_arg(*list, int), count);
	else if (format == 'u')
		ft_putnbr_unsigned(va_arg(*list, unsigned int), count);
	else if (format == 'x')
		ft_putnbr_hex(va_arg(*list, unsigned int), format, count);
	else if (format == 'X')
		ft_putnbr_hex(va_arg(*list, long long int), format, count);
	else if (format == '%')
		*count += write(1, "%", 1);
	else if (format == 'p')
	{
		*count += write(1, "0x", 2);
		ft_put_address(va_arg(*list, unsigned long long), count);
	}
}

int	ft_printf(const char *formatted_string, ...)
{
	va_list	list;
	int		index;
	int		letter_count;

	letter_count = 0;
	va_start(list, formatted_string);
	index = 0;
	while (formatted_string[index] != '\0')
	{
		if (formatted_string[index] == '%')
		{
			ft_print_arg((const char *)&formatted_string[index], \
					&letter_count, &list);
			index++;
		}
		else
			ft_putchr(formatted_string[index], &letter_count);
		index++;
		if (letter_count == -1)
			break ;
	}
	va_end(list);
	return (letter_count);
}
