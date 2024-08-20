/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchaloei <tchaloei@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:45:56 by tchaloei          #+#    #+#             */
/*   Updated: 2024/08/15 12:45:56 by tchaloei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_stack(t_stack *stack)
{
	if (stack->count >= 400)
	{
		redix_sort(stack);
		return ;
	}
	if (stack->top_a->next->next == NULL)
	{
		if (stack->top_a->data > stack->top_a->next->data)
			swap_a(stack);
	}
	else if (stack->top_a->next->next->next == NULL)
		sort3_stack_a(stack);
	else
		four_plus(stack);
}

void	sort3_stack_a(t_stack *stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	first = stack->top_a;
	second = first->next;
	last = first;
	while (last->next)
		last = last->next;
	if (first->data > second->data && first->data < last->data)
		swap_a(stack);
	else if (first->data < second->data && first->data > last->data)
		reverse_a(stack);
	else if (first->data > last->data && last->data > second->data)
		rotate_a(stack);
	else if (first->data > second->data && second->data > last->data)
	{
		swap_a(stack);
		reverse_a(stack);
	}
	else if (first->data < last->data && last->data < second->data)
	{
		reverse_a(stack);
		swap_a(stack);
	}
}

void	four_plus(t_stack *stack)
{
	int	sort;
	int	max;

	sort = sort_stack(stack);
	while (sort != 0)
	{
		four_plus_extend(stack);
		sort = sort_stack(stack);
	}
	if (stack->top_b == NULL)
	{
		freestack(stack);
		exit(0);
	}
	else
	{
		max = find_max(stack);
		while (stack->top_a->data < max)
			push_b(stack);
		push_return(stack);
	}
}

void	four_plus_extend(t_stack *stack)
{
	int	count;

	count = count_stack_a(stack);
	if (count == 3 || count == 2)
	{
		sorting_stack(stack);
		return ;
	}
	if (count > stack->mid_divide + stack->divide + stack->mid)
		sort_more_four1(stack);
	else if (count > stack->mid_divide + stack->divide)
		sort_more_four2(stack);
	else if (count > stack->divide)
		sort_more_four3(stack);
	else if (count > stack->mid_divide)
		sort_more_four4(stack);
	else if (count > stack->mid)
		sort_more_four5(stack);
	else
		sort_more_four6(stack);
}
