/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchaloei <tchaloei@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:04:57 by tchaloei          #+#    #+#             */
/*   Updated: 2024/08/14 18:05:01 by tchaloei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_more_four4(t_stack *stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	first = stack->top_a;
	second = first->next;
	last = stack->top_a;
	while (last->next != NULL)
		last = last->next;
	if (first->position > stack->mid_divide + stack->divide)
	{
		if (last->position > stack->mid_divide + stack->divide)
			rotate_a(stack);
		else
			reverse_a(stack);
	}
	else if (first->data > second->data)
		swap_a(stack);
	else
		push_b(stack);
}

void	sort_more_four5(t_stack *stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	first = stack->top_a;
	second = first->next;
	last = stack->top_a;
	while (last->next != NULL)
		last = last->next;
	if (first->position > stack->mid_divide + stack->divide + stack->mid)
	{
		if (last->position > stack->mid_divide + stack->divide + stack->mid)
			rotate_a(stack);
		else
			reverse_a(stack);
	}
	else if (first->data > second->data)
		swap_a(stack);
	else
		push_b(stack);
}

void	sort_more_four6(t_stack *stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	first = stack->top_a;
	second = first->next;
	last = stack->top_a;
	while (last->next != NULL)
		last = last->next;
	if (first->data > last->data)
	{
		if (last->data > second->data)
			rotate_a(stack);
		else
			reverse_a(stack);
	}
	else if (first->data > second->data)
		swap_a(stack);
	else
		push_b(stack);
}
