/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuartrapoport <stuartrapoport@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:18:59 by stuartrapop       #+#    #+#             */
/*   Updated: 2022/09/12 20:10:39 by stuartrapop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	index;
	char	*substr;

	if (s == NULL)
		return (NULL);
	count = 0;
	if (start >= (unsigned int)ft_strlen(s))
		count = 0;
	else
		while (s[count + start] != '\0' && count < len)
			count++;
	substr = malloc(sizeof(char) * (count + 1));
	if (substr == NULL)
		return (NULL);
	index = 0;
	while (index < count)
	{
		substr[index] = s[index + start];
		index++;
	}
	substr[index] = '\0';
	return (substr);
}
