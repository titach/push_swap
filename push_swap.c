/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchaloei <tchaloei@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:04:15 by tchaloei          #+#    #+#             */
/*   Updated: 2024/08/14 18:04:15 by tchaloei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack *stack)
{
	t_list	*fisrt;
	t_list	*second;

	fisrt = stack->top_a;
	second = stack->top_a->next;
	fisrt->next = stack->top_b;
	stack->top_b = fisrt;
	stack->top_a = second;
	write(1, "pb\n", 3);
}

void	push_a(t_stack *stack)
{
	t_list	*fisrt;
	t_list	*second;

	fisrt = stack->top_b;
	second = stack->top_b->next;
	fisrt->next = stack->top_a;
	stack->top_a = fisrt;
	stack->top_b = second;
	write(1, "pa\n", 3);
}

void	swap_a(t_stack *stack)
{
	t_list	*fisrt;
	t_list	*second;

	fisrt = stack->top_a;
	second = stack->top_a->next;
	fisrt->next = second->next;
	stack->top_a = second;
	second->next = fisrt;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *stack)
{
	t_list	*fisrt;
	t_list	*second;

	fisrt = stack->top_b;
	second = stack->top_b->next;
	fisrt->next = second->next;
	stack->top_b = second;
	second->next = fisrt;
	write(1, "sb\n", 3);
}
