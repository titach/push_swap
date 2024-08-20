/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchaloei <tchaloei@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:04:38 by tchaloei          #+#    #+#             */
/*   Updated: 2024/08/14 18:04:38 by tchaloei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack)
{
	t_list	*fisrt;
	t_list	*second;
	t_list	*last;

	fisrt = stack->top_a;
	second = stack->top_a->next;
	last = stack->top_a;
	while (last->next != NULL)
		last = last->next;
	fisrt->next = last->next;
	stack->top_a = second;
	last->next = fisrt;
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack)
{
	t_list	*fisrt;
	t_list	*second;
	t_list	*last;

	fisrt = stack->top_b;
	second = stack->top_b->next;
	last = stack->top_b;
	while (last->next != NULL)
		last = last->next;
	fisrt->next = last->next;
	stack->top_b = second;
	last->next = fisrt;
	write(1, "rb\n", 3);
}

void	reverse_a(t_stack *stack)
{
	t_list	*fisrt;
	t_list	*pre_last;
	t_list	*last;

	fisrt = stack->top_a;
	pre_last = NULL;
	last = stack->top_a;
	while (last->next != NULL)
	{
		pre_last = last;
		last = last->next;
	}
	pre_last->next = last->next;
	last->next = fisrt;
	stack->top_a = last;
	write(1, "rra\n", 4);
}

void	reverse_b(t_stack *stack)
{
	t_list	*fisrt;
	t_list	*pre_last;
	t_list	*last;

	fisrt = stack->top_b;
	pre_last = NULL;
	last = stack->top_b;
	while (last->next != NULL)
	{
		pre_last = last;
		last = last->next;
	}
	pre_last->next = last->next;
	last->next = fisrt;
	stack->top_b = last;
	write(1, "rrb\n", 4);
}
