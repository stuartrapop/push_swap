/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:55:41 by srapopor          #+#    #+#             */
/*   Updated: 2022/11/09 20:21:09 by srapopor         ###   ########.fr       */
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
	int		*sort_lst;
	int		*position;
	int		median;
}	t_num_list;

void	ft_print_list(int *list, int length);
int		valid_argument(char *string, int *ret);
int		is_sorted_list(int *list, int number_elements, char direction);
int		valid_arguments(int argc, char *argv[]);
void	ft_swap_first_2(t_num_list *list, int show_instruction);
void	ft_rotate_elements(t_num_list *list, int show_instruction);
void	ft_reverse_rotate_elements(t_num_list *list, int show_instruction);
void	ft_rotate_both(t_num_list *list1, t_num_list *list2);
void	ft_reverse_rotate_both(t_num_list *list1, t_num_list *list2);
void	ft_make_position_list(t_num_list *lista, t_num_list *listb);
void	ft_reposition(t_num_list *lista, t_num_list *listb);

#endif