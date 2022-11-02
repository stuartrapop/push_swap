/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:23:56 by srapopor          #+#    #+#             */
/*   Updated: 2022/09/09 19:03:27 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*int_str;
	size_t			index;

	index = 0;
	int_str = (unsigned char *)str;
	while (index < n)
	{
		int_str[index] = (unsigned char)c;
		index++;
	}
	return ((void *)str);
}
