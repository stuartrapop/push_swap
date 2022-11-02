/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuartrapoport <stuartrapoport@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:59:33 by srapopor          #+#    #+#             */
/*   Updated: 2022/09/12 13:30:47 by stuartrapop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*int_dest;
	unsigned char	*int_src;
	size_t			index;

	if (dest == NULL && src == NULL)
		return (NULL);
	int_dest = (unsigned char *)dest;
	int_src = (unsigned char *)src;
	index = 0;
	while (index < n)
	{
		int_dest[index] = int_src[index];
		index++;
	}
	return (dest);
}

//int	main(void)
//{
//	return (0);
//}