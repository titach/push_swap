/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushint_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchaloei <tchaloei@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:04:30 by tchaloei          #+#    #+#             */
/*   Updated: 2024/08/18 13:40:09 by tchaloei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushing_int(int ac, char **av, t_stack	*stack)
{
	char	*num;
	int		i;
	int		j;

	j = ac - 1;
	while (*av)
		av++;
	av--;
	while (*av && j > 0)
	{
		num = *av;
		i = 0;
		while (num[i])
		{
			if (num[i] == ' ' || num[i] == '\t')
			{
				pushing_inside(stack, num);
				break ;
			}
			i++;
		}
		push_stack_a(stack, ft_atol(*av));
		av--;
		j--;
	}
}

void	pushing_inside(t_stack *stack, char *num)
{
	char	*n;
	int		i;

	n = num;
	while (*num)
		num++;
	i = count_str(n);
	while (i > 1)
	{
		while (*num == ' ' || *num == '\t' || *num == '\0')
			num--;
		while (*num != ' ' && *num != '\t')
			num--;
		push_stack_a(stack, ft_atol(num));
		i--;
	}
}

int	count_str(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
			j++;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i++;
	}
	return (j);
}

void	push_stack_a(t_stack *stack, int value)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
	{
		write(2, "Stack Overflow\n", 15);
		return ;
	}
	newnode->data = value;
	newnode->next = stack->top_a;
	stack->top_a = newnode;
}

void	freestack(t_stack *stack)
{
	t_list	*node_a;

	while (stack->top_a != NULL)
	{
		node_a = stack->top_a;
		stack->top_a = stack->top_a->next;
		free(node_a);
	}
	free(stack);
}
