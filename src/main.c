/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:37:10 by tzeck             #+#    #+#             */
/*   Updated: 2022/03/27 20:17:12 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	delete_stack(t_stack *stack)
{
	int		i;
	t_node	*tmp;

	i = 0;
	while (i < stack->size)
	{
		tmp = stack->head->next;
		free(stack->head);
		stack->head = tmp;
		i++;
	}
	free(stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_a = get_input(argc, argv, stack_a);
	stack_b = new_stack();
	if (stack_a == NULL || stack_a->head == NULL)
	{
		delete_stack(stack_b);
		return (0);
	}
	sort(&stack_a, &stack_b);
	delete_stack(stack_a);
	delete_stack(stack_b);
	return (0);
}
