/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:29:00 by tom               #+#    #+#             */
/*   Updated: 2021/12/20 23:35:03 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_stack **stack_a, int print)
{
	(*stack_a)->head = (*stack_a)->head->next;
	if (print == 1)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **stack_b, int print)
{
	(*stack_b)->head = (*stack_b)->head->next;
	if (print == 1)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	ft_putstr_fd("rr\n", 1);
}
