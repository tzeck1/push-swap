/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:41:28 by tom               #+#    #+#             */
/*   Updated: 2021/12/20 23:36:17 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_stack **stack_a, int print)
{
	(*stack_a)->head = (*stack_a)->head->prev;
	if (print == 1)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **stack_b, int print)
{
	(*stack_b)->head = (*stack_b)->head->prev;
	if (print == 1)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	ft_putstr_fd("rrr\n", 1);
}
