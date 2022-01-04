/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:39:45 by tom               #+#    #+#             */
/*   Updated: 2021/12/29 16:25:50 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/*	finds smallest node in stack_a and pushes to stack_b	*/
void	push_small(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*small;
	int		index;

	small = find_small(stack_a);
	index = get_index(stack_a, small);
	while ((*stack_a)->head != small)
	{
		if (index > (float)((*stack_a)->size / 2))
			rra(stack_a, 1);
		else
			ra(stack_a, 1);
	}
	pb(stack_a, stack_b);
}

/* 	pushes smallest node to stack_b
	applys sort_three and pushes smallest node back to stack_a	*/
void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	push_small(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}
