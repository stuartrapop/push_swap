/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:55:41 by srapopor          #+#    #+#             */
/*   Updated: 2022/11/10 16:34:57 by srapopor         ###   ########.fr       */
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
int		valid_argument(char *string);
int		is_sorted_list(int *list, int number_elements, char direction);
int		valid_arguments(int argc, char *argv[]);
void	ft_swap_first_2(t_num_list *list, int show_instruction);
void	ft_rotate_elements(t_num_list *list, int show_instruction);
void	ft_reverse_rotate_elements(t_num_list *list, int show_instruction);
void	ft_make_position_list(t_num_list *lista, t_num_list *listb);
void	ft_radix_b4_push_0(t_num_list *lista, t_num_list *listb, int column);
void	ft_radix_b4_push_1(t_num_list *lista, t_num_list *listb, int column);
void	ft_radix_b4_push_2(t_num_list *lista, t_num_list *listb, int column);
void	ft_radix_4(t_num_list *lista, t_num_list *listb);
void	ft_merge(t_num_list *lista, t_num_list *listb);
void	ft_get_list_stats(t_num_list *list);
void	ft_make_sort_list(t_num_list *lista);
void	ft_push(t_num_list *list1, t_num_list *list2);
void	ft_radix_b3_push_0(t_num_list *lista, t_num_list *listb, int column);
void	ft_radix_b3_push_1(t_num_list *lista, t_num_list *listb, int column);
void	ft_radix_3(t_num_list *lista, t_num_list *listb);
void	ft_sort_few(t_num_list *lista, t_num_list *listb);
void	ft_radix_2(t_num_list *lista, t_num_list *listb);
void	ft_sort_less_3(t_num_list *list);
int		ft_none_left(t_num_list list, int start, int end);

#endif