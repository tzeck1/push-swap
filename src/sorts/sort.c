/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:50:13 by tom               #+#    #+#             */
/*   Updated: 2022/01/01 14:08:52 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*	goes through stack_a and checks if stack 
	is already sorted after reding input	*/
static int	checker(t_stack **stack_a)
{
	int	i;

	i = 0;
	while (i != (*stack_a)->size - 1)
	{
		if ((*stack_a)->nodes->data > (*stack_a)->nodes->next->data)
			return (0);
		(*stack_a)->nodes = (*stack_a)->nodes->next;
		i++;
	}
	(*stack_a)->nodes = (*stack_a)->head;
	return (1);
}

/*	calls different sort functions up to five nodes	*/
static void	small_sort(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->size == 2)
	{
		if ((*stack_a)->head->data > (*stack_a)->head->next->data)
			sa(stack_a, 1);
	}
	else if ((*stack_a)->size == 3)
		sort_three(stack_a);
	else if ((*stack_a)->size == 4)
		sort_four(stack_a, stack_b);
	else if ((*stack_a)->size == 5)
		sort_five(stack_a, stack_b);
}

/*	calls different sort functions, dependend on node number	*/
void	sort(t_stack **stack_a, t_stack **stack_b)
{
	if (checker(stack_a) == 1)
		return ;
	else if ((*stack_a)->size <= 5)
		small_sort(stack_a, stack_b);
	else if ((*stack_a)->size <= 100)
		medium_sort(stack_a, stack_b);
	else
		large_sort(stack_a, stack_b);
}
