/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 23:00:42 by tom               #+#    #+#             */
/*   Updated: 2021/12/22 05:10:35 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/* 	pushes two smallest nodes to stack_b
	applys sort_three and pushes two smallest nodes back to stack_a	*/
void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	push_small(stack_a, stack_b);
	push_small(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
