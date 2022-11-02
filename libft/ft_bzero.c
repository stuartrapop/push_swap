/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuartrapoport <stuartrapoport@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:18:46 by stuartrapop       #+#    #+#             */
/*   Updated: 2022/09/12 13:29:28 by stuartrapop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			index;
	unsigned char	*int_s;

	int_s = s;
	index = 0;
	while (index < n)
	{
		int_s[index] = '\0';
		index++;
	}
}
