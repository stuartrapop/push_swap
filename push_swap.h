/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:55:41 by srapopor          #+#    #+#             */
/*   Updated: 2022/10/30 13:32:39 by srapopor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

t_list	*ft_remove_and_return_first(t_list **lst);
t_list	*ft_remove_and_return_last(t_list **lst);
void	swap_first_two(t_list **lst);
void	rotate_list(t_list **lst);
void	rotate_reverse_list(t_list **lst);

#endif