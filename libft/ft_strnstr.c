/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuartrapoport <stuartrapoport@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:11:04 by srapopor          #+#    #+#             */
/*   Updated: 2022/09/12 20:10:48 by stuartrapop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index1;
	size_t	index2;

	if ((needle[0] == '\0'))
		return ((char *)haystack);
	if (haystack == NULL && len == 0)
		return (NULL);
	index1 = 0;
	while (haystack[index1] != '\0' && index1 < len)
	{
		index2 = 0;
		while (needle[index2] != '\0' && (haystack[index1 + index2] \
			== needle[index2]) && (index1 + index2) < len)
			index2++;
		if (ft_strlen(needle) == (int)index2)
			return ((char *)&haystack[index1]);
		index1++;
	}
	return (NULL);
}
