/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchaloei <tchaloei@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:04:50 by tchaloei          #+#    #+#             */
/*   Updated: 2024/08/14 18:04:50 by tchaloei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_return(t_stack *stack)
{
	int	max;

	while (stack->top_b != NULL)
	{
		max = find_max(stack);
		if (max == stack->top_b->data)
			push_a(stack);
		else
		{
			stack->count = count_stack_b(stack);
			if (stack->count == 2)
			{
				swap_b(stack);
				push_a(stack);
				push_a(stack);
				break ;
			}
			stack->pos = find_position(stack, max);
			if (stack->count % 2 == 0)
				stack->range = stack->count / 2;
			else
				stack->range = stack->count / 2 + 1;
			push_return2(stack, max);
		}
	}
}

void	push_return2(t_stack *stack, int max)
{
	while (max != stack->top_b->data)
	{
		if (stack->pos <= stack->range)
			rotate_b(stack);
		else
			reverse_b(stack);
		max = find_max(stack);
	}
}

void	sort_more_four1(t_stack *stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	first = stack->top_a;
	second = first->next;
	last = stack->top_a;
	while (last->next != NULL)
		last = last->next;
	if (first->position > stack->mid)
	{
		if (last->position > stack->mid)
			rotate_a(stack);
		else
			reverse_a(stack);
	}
	else if (first->data > second->data)
		swap_a(stack);
	else
		push_b(stack);
}

void	sort_more_four2(t_stack *stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	first = stack->top_a;
	second = first->next;
	last = stack->top_a;
	while (last->next != NULL)
		last = last->next;
	if (first->position > stack->mid_divide)
	{
		if (last->position > stack->mid_divide)
			rotate_a(stack);
		else
			reverse_a(stack);
	}
	else if (first->data > second->data)
		swap_a(stack);
	else
		push_b(stack);
}

void	sort_more_four3(t_stack *stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	first = stack->top_a;
	second = first->next;
	last = stack->top_a;
	while (last->next != NULL)
		last = last->next;
	if (first->position > stack->divide)
	{
		if (last->position > stack->divide)
			rotate_a(stack);
		else
			reverse_a(stack);
	}
	else if (first->data > second->data)
		swap_a(stack);
	else
		push_b(stack);
}
