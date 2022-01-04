/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:07:13 by tom               #+#    #+#             */
/*   Updated: 2021/12/29 14:07:27 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/*	calls  stack_operations to sort stack_a, dependend on arrangement	*/
static void	edit_stack(t_stack **stack_a, int n)
{
	if (n == 1)
		sa(stack_a, 1);
	if (n == 2)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	if (n == 3)
		ra(stack_a, 1);
	if (n == 4)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	if (n == 5)
		rra(stack_a, 1);
}

/*	compares node values and calls sorting algorithm (edit-stack)	*/
void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->head->data;
	b = (*stack_a)->head->next->data;
	c = (*stack_a)->head->next->next->data;
	if (a > b && b < c && c > a)
		edit_stack(stack_a, 1);
	else if (a > b && b > c && c < a)
		edit_stack(stack_a, 2);
	else if (a > b && b < c && c < a)
		edit_stack(stack_a, 3);
	else if (a < b && b > c && c > a)
		edit_stack(stack_a, 4);
	else if (a < b && b > c && c < a)
		edit_stack(stack_a, 5);
}
