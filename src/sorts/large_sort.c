/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:37:53 by tom               #+#    #+#             */
/*   Updated: 2021/12/22 17:42:40 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_higher(t_stack **stack_a, t_stack **stack_b, long low, long high)
{
	int	start;
	int	end;

	start = low + (7 * ((high - low) / 8));
	end = high;
	push_range(stack_a, stack_b, start, end);
	while ((*stack_b)->size != 0)
		compare_moves(stack_a, stack_b);
	start = low + (6 * ((high - low) / 8));
	end = low + (7 * ((high - low) / 8));
	push_range(stack_a, stack_b, start, end);
	while ((*stack_b)->size != 0)
		compare_moves(stack_a, stack_b);
	start = low + (5 * ((high - low) / 8));
	end = low + (6 * ((high - low) / 8));
	push_range(stack_a, stack_b, start, end);
	while ((*stack_b)->size != 0)
		compare_moves(stack_a, stack_b);
	start = low + (4 * ((high - low) / 8));
	end = low + (5 * ((high - low) / 8));
	push_range(stack_a, stack_b, start, end);
	while ((*stack_b)->size != 0)
		compare_moves(stack_a, stack_b);
}

void	sort_lower(t_stack **stack_a, t_stack **stack_b, long low, long high)
{
	int	start;
	int	end;

	start = low + (3 * ((high - low) / 8));
	end = low + (4 * ((high - low) / 8));
	push_range(stack_a, stack_b, start, end);
	while ((*stack_b)->size != 0)
		compare_moves(stack_a, stack_b);
	start = low + (2 * ((high - low) / 8));
	end = low + (3 * ((high - low) / 8));
	push_range(stack_a, stack_b, start, end);
	while ((*stack_b)->size != 0)
		compare_moves(stack_a, stack_b);
	start = low + ((high - low) / 8);
	end = low + (2 * ((high - low) / 8));
	push_range(stack_a, stack_b, start, end);
	while ((*stack_b)->size != 0)
		compare_moves(stack_a, stack_b);
	start = low;
	end = low + ((high - low) / 8);
	push_range(stack_a, stack_b, start, end);
	while ((*stack_b)->size != 0)
		compare_moves(stack_a, stack_b);
}

void	large_sort(t_stack **stack_a, t_stack **stack_b)
{
	long	low;
	long	high;
	t_node	*small;

	low = find_small(stack_a)->data;
	high = find_large(stack_a)->data;
	sort_higher(stack_a, stack_b, low, high);
	sort_lower(stack_a, stack_b, low, high);
	small = find_small(stack_a);
	while (small != (*stack_a)->head)
		rra(stack_a, 1);
}
