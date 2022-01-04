/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:02:51 by tzeck             #+#    #+#             */
/*   Updated: 2022/01/01 14:00:26 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "stack.h"
# include "../libft/libft.h"

t_stack	*get_input(int argc, char **argv, t_stack *stack);
/*	swap-operations	*/
void	sa(t_stack **stack_a, int print);
void	sb(t_stack **stack_b, int print);
void	ss(t_stack **stack_a, t_stack **stack_b);
/*	push-operations	*/
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
/*	rotate-operations	*/
void	ra(t_stack **stack_a, int print);
void	rb(t_stack **stack_b, int print);
void	rr(t_stack **stack_a, t_stack **stack_b);
/*	reverse_rotate-operations	*/
void	rra(t_stack **stack_a, int print);
void	rrb(t_stack **stack_a, int print);
void	rrr(t_stack **stack_a, t_stack **stack_b);
/*	sorts	*/
void	sort(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack_a);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	medium_sort(t_stack **stack_a, t_stack **stack_b);
void	large_sort(t_stack **stack_a, t_stack **stack_b);
void	compare_moves(t_stack **stack_a, t_stack **stack_b);
void	push_small_b(t_stack **stack_a, t_stack **stack_b, t_node *node);
void	push_large_b(t_stack **stack_a, t_stack **stack_b, t_node *node);
/*	help-functions	*/
void	free_node(t_node **node);
t_node	*find_small(t_stack **stack);
t_node	*find_large(t_stack **stack);
void	push_small(t_stack **stack_a, t_stack **stack_b);
int		get_index(t_stack **stack, t_node *node);
void	delete_node(t_stack **stack);
int		check_for_neg(t_stack **stack_b, int i);
void	push_range(t_stack **stack_a, t_stack **stack_b, int start, int end);
void	smart_rotate(t_stack **stack, t_node *node);
void	delete_stack(t_stack *stack);
int		invalid(t_stack *stack, int invalid_input);
void	free_split_node(t_node *node, char **split);
void	delete_split(char **split);

#endif
