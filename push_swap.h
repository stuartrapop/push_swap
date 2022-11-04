/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:55:41 by srapopor          #+#    #+#             */
/*   Updated: 2022/11/04 14:14:55 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H



typedef struct s_node
{
	int				content;
	int				first_element;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

t_node	*ft_remove_and_return_first(t_node **lst);
t_node	*ft_remove_and_return_last(t_node **lst);
void	ft_add_front(t_node **lst, t_node *new);
void	ft_add_back(t_node **lst, t_node *new);
void	swap_first_two(t_node **lst);
void	rotate_list(t_node **lst, char *lst_name);
void	rotate_reverse_list(t_node **lst, char *lst_name);
void	ft_delete_lst(t_node **lst);
t_node	*ft_create_node(int number);
int		ft_count_elements(t_node *lst);
void	ft_print_list(t_node *lst);
int		valid_argument(char *string, int *ret);
int		ft_max_value(t_node *lst);
int		ft_compare_swap_rotate(t_node **lst, char *lst_name, char *direction,
			int num_sorted);


typedef struct s_list
{
	int max_value;
	int min_value;
	int median;
	int number_elements;
	char name;
} t_list;

#endif