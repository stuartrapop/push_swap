/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuartrapoport <stuartrapoport@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:55:00 by srapopor          #+#    #+#             */
/*   Updated: 2022/09/12 20:11:42 by stuartrapop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	initial_length;

	if (dstsize == 0)
		return (ft_strlen(src) + dstsize);
	initial_length = ft_strlen(dst);
	index = 0;
	while (src[index] != '\0' && (index + initial_length + 1 < dstsize))
	{
		dst[initial_length + index] = src[index];
		index++;
	}
	dst[initial_length + index] = '\0';
	if (dstsize < initial_length)
		return (ft_strlen(src) + dstsize);
	return ((size_t)(initial_length + ft_strlen(src)));
}
