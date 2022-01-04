/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:20:42 by tzeck             #+#    #+#             */
/*   Updated: 2021/12/22 17:27:25 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_split_node(t_node *node, char **split)
{
	delete_split(split);
	free(node);
}

int	invalid(t_stack *stack, int invalid_input)
{
	if (invalid_input == 1)
	{
		ft_putstr_fd("Error\n", 2);
		delete_stack(stack);
		return (1);
	}
	return (0);
}
