/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchaloei <student.42bangkok.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:37:51 by tchaloei          #+#    #+#             */
/*   Updated: 2024/08/19 21:37:51 by tchaloei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	redix_sort(t_stack *stack)
{
	int	sort;

	get_binary(stack);
	sort = sort_stack(stack);
	while (sort != 0)
	{
		stack->count = count_stack_a(stack);
		while (stack->count != 0)
		{
			if (stack->top_a->binary % 2 == 1)
			{
				stack->top_a->binary /= 10;
				rotate_a(stack);
			}
			else
			{
				stack->top_a->binary /= 10;
				push_b(stack);
			}
			stack->count--;
		}
		while (stack->top_b != NULL)
			push_a(stack);
		sort = sort_stack(stack);
	}
}

void	get_binary(t_stack *stack)
{
	t_list	*in;

	in = stack->top_a;
	while (in != NULL)
	{
		in->binary = itobi(in->position);
		in = in->next;
	}
}
