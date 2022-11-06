/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:55:41 by srapopor          #+#    #+#             */
/*   Updated: 2022/11/05 19:40:21 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_num_list
{
	int		max_value;
	int		min_value;
	int		number_elements;
	char	identifier;
	int		*elements;
}	t_num_list;

void	ft_print_list(t_num_list list);
int		valid_argument(char *string, int *ret);
int		is_sorted_list(int *list, int number_elements);
int		valid_arguments(int argc, char *argv[]);
void	ft_simple_sort(int **list, int length);

#endif