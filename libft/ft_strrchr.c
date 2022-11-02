/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 08:51:27 by srapopor          #+#    #+#             */
/*   Updated: 2022/09/15 10:55:24 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	int	length;
	int	index;

	length = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return ((char *)(s + length * sizeof(char)));
	index = length - 1;
	while (index >= 0)
	{
		if ((unsigned char)c == (unsigned char)s[index])
			return ((char *)(s + index * sizeof(char)));
		index--;
	}
	return (NULL);
}
