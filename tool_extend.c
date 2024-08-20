/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_extend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchaloei <tchaloei@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:05:14 by tchaloei          #+#    #+#             */
/*   Updated: 2024/08/14 18:05:14 by tchaloei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_stack(t_stack *stack)
{
	t_list	*fisrt;
	t_list	*second;
	int		i;

	i = 1;
	fisrt = stack->top_a;
	second = stack->top_a->next;
	while (fisrt->data < second->data && second->next != NULL)
	{
		fisrt = fisrt->next;
		second = second->next;
	}
	if (fisrt->data < second->data && second->next == NULL)
		i = 0;
	return (i);
}

int	count_stack_a(t_stack *stack)
{
	t_list	*first;
	int		i;

	i = 1;
	first = stack->top_a;
	while (first->next != NULL)
	{
		i++;
		first = first->next;
	}
	return (i);
}

int	count_stack_b(t_stack *stack)
{
	t_list	*first;
	int		i;

	i = 1;
	first = stack->top_b;
	while (first->next != NULL)
	{
		i++;
		first = first->next;
	}
	return (i);
}

int	find_max(t_stack *stack)
{
	t_list	*max;
	int		value;

	max = stack->top_b;
	value = max->data;
	while (max->next != NULL)
	{
		if (value < max->next->data)
			value = max->next->data;
		max = max->next;
	}
	return (value);
}

int	find_position(t_stack *stack, int data)
{
	t_list	*find;
	int		i;

	i = 1;
	find = stack->top_b;
	while (find->next != NULL)
	{
		if (find->data == data)
			break ;
		i++;
		find = find->next;
	}
	return (i);
}
