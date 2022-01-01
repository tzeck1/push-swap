/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:09:47 by tom               #+#    #+#             */
/*   Updated: 2021/12/22 17:19:24 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	delete_node(t_stack **stack)
{
	if ((*stack)->size == 1)
	{
		delete_stack(*stack);
		*stack = new_stack();
		return ;
	}
	(*stack)->head->prev->next = (*stack)->head->next;
	(*stack)->head->next->prev = (*stack)->head->prev;
	free((*stack)->head);
	(*stack)->head = (*stack)->head->next;
	(*stack)->nodes = (*stack)->head;
	(*stack)->size--;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*node;

	if ((*stack_b)->head == NULL)
		return ;
	node = new_node();
	node->data = (*stack_b)->head->data;
	node->index = (*stack_b)->head->index;
	add_back(stack_a, node);
	(*stack_a)->head = (*stack_a)->head->prev;
	(*stack_a)->nodes = (*stack_a)->head;
	delete_node(stack_b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*node;

	if ((*stack_a)->head == NULL)
		return ;
	node = new_node();
	node->data = (*stack_a)->head->data;
	node->index = (*stack_a)->head->index;
	add_back(stack_b, node);
	(*stack_b)->head = (*stack_b)->head->prev;
	(*stack_b)->nodes = (*stack_b)->head;
	delete_node(stack_a);
	ft_putstr_fd("pb\n", 1);
}
