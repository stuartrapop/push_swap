/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuartrapoport <stuartrapoport@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:39:02 by stuartrapop       #+#    #+#             */
/*   Updated: 2022/09/12 16:02:08 by stuartrapop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*new_memory;

	new_memory = malloc(count * size);
	if (!new_memory)
		return (NULL);
	ft_bzero(new_memory, count * size);
	return (new_memory);
}
