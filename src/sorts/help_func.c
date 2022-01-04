/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:34:42 by tom               #+#    #+#             */
/*   Updated: 2022/01/01 13:47:22 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_index(t_stack **stack, t_node *node)
{
	int	i;

	i = 0;
	while ((*stack)->nodes != node)
	{
		i++;
		(*stack)->nodes = (*stack)->nodes->next;
	}
	(*stack)->nodes = (*stack)->head;
	return (i);
}

t_node	*find_small(t_stack **stack)
{
	t_node	*small;
	int		i;

	i = 0;
	small = (*stack)->head;
	while (i != (*stack)->size)
	{
		if (small->data > (*stack)->nodes->data)
			small = (*stack)->nodes;
		(*stack)->nodes = (*stack)->nodes->next;
		i++;
	}
	small->index = i;
	(*stack)->nodes = (*stack)->head;
	return (small);
}

t_node	*find_large(t_stack **stack)
{
	t_node	*large;
	int		i;

	i = 0;
	large = (*stack)->head;
	while (i != (*stack)->size)
	{
		if (large->data < (*stack)->nodes->data)
			large = (*stack)->nodes;
		(*stack)->nodes = (*stack)->nodes->next;
		i++;
	}
	large->index = i;
	(*stack)->nodes = (*stack)->head;
	return (large);
}
