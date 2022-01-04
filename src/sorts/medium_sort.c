/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:37:53 by tom               #+#    #+#             */
/*   Updated: 2022/01/01 13:47:59 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_small_b(t_stack **stack_a, t_stack **stack_b, t_node *node)
{
	int	index;

	index = get_index(stack_b, node);
	while (node != (*stack_b)->head)
	{
		if (index > ((*stack_b)->size / 2))
			rrb(stack_b, 1);
		else
			rb(stack_b, 1);
	}
	pa(stack_a, stack_b);
}

void	push_large_b(t_stack **stack_a, t_stack **stack_b, t_node *node)
{
	int	index;

	index = get_index(stack_b, node);
	while (node != (*stack_b)->head)
	{
		if (index > ((*stack_b)->size / 2))
			rrb(stack_b, 1);
		else
			rb(stack_b, 1);
	}
	smart_rotate(stack_b, node);
	pa(stack_a, stack_b);
}

void	compare_moves(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*small;
	t_node	*large;
	int		left;
	int		right;

	small = find_small(stack_b);
	large = find_large(stack_b);
	left = check_for_neg(stack_b, get_index((stack_b), small));
	right = check_for_neg(stack_b, get_index((stack_b), large));
	if (left > right)
	{
		push_small_b(stack_a, stack_b, small);
		ra(stack_a, 1);
	}
	else
		push_large_b(stack_a, stack_b, large);
}

static void	sorting(t_stack **stack_a, t_stack **stack_b, long low, long high)
{
	long	start;
	long	end;

	start = low + (3 * ((high - low) / 4));
	end = high;
	push_range(stack_a, stack_b, start, end);
	while ((*stack_b)->size != 0)
		compare_moves(stack_a, stack_b);
	start = low + (2 * ((high - low) / 4));
	end = low + (3 * ((high - low) / 4));
	push_range(stack_a, stack_b, start, end);
	while ((*stack_b)->size != 0)
		compare_moves(stack_a, stack_b);
	start = low + ((high - low) / 4);
	end = low + (2 * ((high - low) / 4));
	push_range(stack_a, stack_b, start, end);
	while ((*stack_b)->size != 0)
		compare_moves(stack_a, stack_b);
	start = low;
	end = low + ((high - low) / 4);
	push_range(stack_a, stack_b, start, end);
	while ((*stack_b)->size != 0)
		compare_moves(stack_a, stack_b);
}

void	medium_sort(t_stack **stack_a, t_stack **stack_b)
{
	long	low;
	long	high;
	t_node	*small;

	low = find_small(stack_a)->data;
	high = find_large(stack_a)->data;
	sorting(stack_a, stack_b, low, high);
	small = find_small(stack_a);
	while (small != (*stack_a)->head)
		rra(stack_a, 1);
}
