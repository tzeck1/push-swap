/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:54:10 by tzeck             #+#    #+#             */
/*   Updated: 2021/12/22 05:40:31 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_node(t_node **node)
{
	free(*node);
	*node = NULL;
}

t_stack	*new_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->size = 0;
	stack->head = NULL;
	stack->nodes = stack->head;
	return (stack);
}

t_node	*new_node(void)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->data = 0;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

/*	adds new node to stack, for add_front moving pointer after call	*/
void	add_back(t_stack **stack, t_node *new)
{
	if ((*stack)->head == NULL)
	{
		(*stack)->head = new;
		(*stack)->nodes = new;
		(*stack)->head->next = new;
		(*stack)->head->prev = new;
	}
	new->next = (*stack)->head;
	new->prev = (*stack)->head->prev;
	(*stack)->head->prev->next = new;
	(*stack)->head->prev = new;
	(*stack)->size++;
}
