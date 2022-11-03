/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:48:04 by srapopor          #+#    #+#             */
/*   Updated: 2022/10/20 16:36:00 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_printf(const char *formatted_string, ...);
void	ft_putnbr_hex(unsigned int n, char format, int *letter_count);
void	ft_putnbr_unsigned(unsigned int n, int *letter_count);
void	ft_put_address(unsigned long n, int *letter_count);
void	ft_putchr(char c, int *count);

#endif