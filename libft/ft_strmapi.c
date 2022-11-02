/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:21:05 by srapopor          #+#    #+#             */
/*   Updated: 2022/09/14 16:32:33 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	int		length;
	char	*mapped_string;

	index = 0;
	length = ft_strlen(s);
	if (s == NULL || f == NULL)
		return (NULL);
	mapped_string = malloc(sizeof(char) * (length + 1));
	if (!mapped_string)
		return (NULL);
	while (s[index] != '\0')
	{
		mapped_string[index] = (*f)(index, s[index]);
		index++;
	}
	mapped_string[index] = '\0';
	return (mapped_string);
}
