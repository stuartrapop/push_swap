/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuartrapoport <stuartrapoport@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:59:33 by srapopor          #+#    #+#             */
/*   Updated: 2022/09/12 13:30:21 by stuartrapop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*int_dest;
	unsigned char	*int_src;
	size_t			index;
	int				c_found;

	if (dest == NULL && src == NULL)
		return (NULL);
	int_dest = (unsigned char *)dest;
	int_src = (unsigned char *)src;
	index = 0;
	c_found = 0;
	while (index < n && !c_found)
	{
		int_dest[index] = int_src[index];
		if (int_src[index] == (unsigned char)c)
			c_found = 1;
		index++;
	}
	if (c_found)
		return (&int_dest[index]);
	return (NULL);
}

//int	main(void)
//{
//	return (0);
//}