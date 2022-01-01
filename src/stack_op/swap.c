/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:18:52 by tom               #+#    #+#             */
/*   Updated: 2021/12/22 05:10:01 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap(long *value_a, long *value_b)
{
	long	tmp;

	tmp = *value_a;
	*value_a = *value_b;
	*value_b = tmp;
}

void	sa(t_stack **stack_a, int print)
{
	swap(&(*stack_a)->head->data, &(*stack_a)->head->next->data);
	if (print == 1)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **stack_b, int print)
{
	swap(&(*stack_b)->head->data, &(*stack_b)->head->next->data);
	if (print == 1)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	ft_putstr_fd("ss\n", 1);
}
