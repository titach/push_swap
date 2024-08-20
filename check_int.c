/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchaloei <tchaloei@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:45:22 by tchaloei          #+#    #+#             */
/*   Updated: 2024/08/19 13:10:26 by tchaloei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_int(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atol(av[i]) == 0)
			check_equal_to_zero(av[i]);
		if (ft_atol(av[i]) < INT_MIN || ft_atol(av[i]) > INT_MAX)
			msg_error(1);
		check_string(av[i]);
		i++;
	}
}

void	check_equal_to_zero(char *av)
{
	int	j;
	int	k;
	int	s;

	k = 0;
	s = 0;
	j = 0;
	while (av[j])
	{
		if (av[j] == '0')
			s++;
		j++;
	}
	if (s > 0)
		k = 1;
	if (k == 0)
		msg_error(1);
}

void	check_string(char *str)
{
	while (*str)
	{
		while (*str == ' ' || *str == '\t')
			str++;
		if (ft_atol(str) == 0 && *str != '\0' && *str != '0')
		{
			if (*str == '-' || *str == '+')
			{
				str++;
				if (*str != '0')
					msg_error(1);
			}
		}
		if (ft_atol(str) < INT_MIN || ft_atol(str) > INT_MAX)
			msg_error(1);
		if (*str == '-' || *str == '+')
			str++;
		while (*str && *str != ' ' && *str != '\t')
		{
			if ((*str < 48 || *str > 57))
				msg_error(1);
			str++;
		}
	}
}

void	check_repeat(t_stack *stack)
{
	t_list	*nbr;
	t_list	*num;
	int		i;

	nbr = stack->top_a;
	while (nbr)
	{
		i = 0;
		num = stack->top_a;
		while (num)
		{
			if (nbr->data == num->data)
				i++;
			num = num->next;
		}
		nbr = nbr->next;
		if (i > 1)
		{
			freestack(stack);
			msg_error(1);
		}
	}
}

void	msg_error(int n)
{
	write(2, "Error\n", 6);
	exit(n);
}
