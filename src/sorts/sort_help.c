/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 05:18:57 by tzeck             #+#    #+#             */
/*   Updated: 2022/01/01 13:46:41 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	smart_rotate(t_stack **stack, t_node *node)
{
	int		i;

	i = get_index(stack, node);
	while (node != (*stack)->head)
	{
		if (i > ((*stack)->size / 2))
			rra(stack, 1);
		else
			ra(stack, 1);
	}
}

// void	push_below(t_stack **stack_a, t_stack **stack_b, int start, int end)
// {
// 	int		i;
// 	int		size;
// 	t_node	*node;

// 	i = 0;
// 	size = (*stack_a)->size;
// 	node = (*stack_a)->head;
// 	while (i <= size)
// 	{
// 		if (node->data >= start && node->data <= end)
// 		{
// 			smart_rotate(stack_a, node);
// 			pb(stack_a, stack_b);
// 		}
// 		node = node->next;
// 		i++;
// 	}
// }

void	push_range(t_stack **stack_a, t_stack **stack_b, int start, int end)
{
	int		i;
	int		size;
	t_node	*node;

	i = 0;
	size = (*stack_a)->size;
	node = (*stack_a)->head;
	while (i <= size)
	{
		if (node->data >= start && node->data <= end)
		{
			smart_rotate(stack_a, node);
			pb(stack_a, stack_b);
		}
		node = node->next;
		i++;
	}
}

int	check_for_neg(t_stack **stack_b, int i)
{
	if ((((*stack_b)->size / 2) - i) < 0)
		return ((((*stack_b)->size / 2) - i) * -1);
	else
		return ((((*stack_b)->size / 2) - i));
}
