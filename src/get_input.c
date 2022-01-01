/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:50:15 by tzeck             #+#    #+#             */
/*   Updated: 2021/12/22 18:41:53 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_for_dup(long n, t_stack *stack)
{
	int	i;
	int	size;

	if (stack->head == NULL)
		return (0);
	i = 0;
	size = stack->size;
	while (i != size)
	{
		if (n == stack->nodes->data)
		{
			stack->nodes = stack->head;
			return (1);
		}
		stack->nodes = stack->nodes->next;
		i++;
	}
	stack->nodes = stack->head;
	return (0);
}

void	delete_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free (split);
}

long	check_error(char **split_input, int i, int *inval_input, t_stack *stack)
{
	long	n;

	if (ft_isdigit_string(split_input[i]) == 0)
	{
		*inval_input = 1;
		delete_split(split_input);
		return (0);
	}
	n = ft_atoi(split_input[i]);
	if (n > 2147483647 || n < -2147483648 || check_for_dup(n, stack) == 1)
	{
		*inval_input = 1;
		delete_split(split_input);
		return (0);
	}
	delete_split(split_input);
	return (n);
}

t_node	*input_cleaner(char *input, t_stack *stack, int *inval_input)
{
	char		**split_input;
	static int	i;
	static int	index;
	long		n;
	t_node		*node;

	node = new_node();
	split_input = ft_split(input, ' ');
	if (split_input[i] != NULL)
	{
		n = check_error(split_input, i, inval_input, stack);
		if (*inval_input == 1)
		{
			free(node);
			return (NULL);
		}
		node->data = n;
		node->index = index;
		index++;
		i++;
		return (node);
	}
	i = 0;
	free_split_node(node, split_input);
	return (NULL);
}

t_stack	*get_input(int argc, char **argv, t_stack *stack)
{
	int		i;
	int		inval_input;
	t_node	*node;

	i = 1;
	inval_input = 0;
	stack = new_stack();
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 0)
		{
			i++;
			continue ;
		}
		node = input_cleaner(argv[i], stack, &inval_input);
		if (invalid(stack, inval_input) == 1)
			return (NULL);
		if (node == NULL)
			i++;
		if (node == NULL)
			continue ;
		add_back(&stack, node);
	}
	return (stack);
}
