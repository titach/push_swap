/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchaloei <tchaloei@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:04:06 by tchaloei          #+#    #+#             */
/*   Updated: 2024/08/14 18:04:06 by tchaloei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_position(t_list *box, t_stack *stack)
{
	t_list	*num;
	int		count;
	int		i;

	i = 0;
	count = count_stack_a(stack);
	num = stack->top_a;
	while (num != NULL)
	{
		if (box->data < num->data)
			i += 1;
		num = num->next;
	}
	box->position = count - i;
}

void	get_value(t_stack *stack)
{
	t_list	*first;

	first = stack->top_a;
	while (first != NULL)
	{
		get_position(first, stack);
		first = first->next;
	}
	stack->count = count_stack_a(stack);
	stack->divide = stack->count / 2;
	if (stack->count % 2 != 0)
		stack->divide = stack->divide + 1;
	stack->mid_divide = stack->divide / 2;
	if (stack->divide % 2 != 0)
		stack->mid_divide = stack->mid_divide + 1;
	stack->mid = stack->mid_divide / 2;
	if (stack->mid_divide % 2 != 0)
		stack->mid = stack->mid + 1;
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac == 1)
		return (0);
	check_int(av);
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		exit(EXIT_FAILURE);
	stack->top_a = NULL;
	stack->top_b = NULL;
	pushing_int(ac, av, stack);
	check_repeat(stack);
	get_value(stack);
	if (stack->top_a->next != NULL)
		sorting_stack(stack);
	freestack(stack);
	return (0);
}
