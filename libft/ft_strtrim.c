/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:26:52 by stuartrapop       #+#    #+#             */
/*   Updated: 2022/09/13 15:31:38 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_inset(const char c, char const *set)
{
	int	index;

	index = 0;
	while (set[index] != '\0')
	{
		if ((unsigned char)c == (unsigned char)set[index])
			return (1);
		index++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_str;
	int		index;
	int		start;
	int		end;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_inset(s1[start], set))
		start++;
	while (ft_inset(s1[end], set) && end > start)
		end--;
	trimmed_str = malloc(sizeof(char) * (end - start + 2));
	if (!trimmed_str)
		return (NULL);
	index = 0;
	while (index < (end - start + 1))
	{
		trimmed_str[index] = s1[index + start];
		index++;
	}
	trimmed_str[index] = '\0';
	return (trimmed_str);
}
