/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchaloei <tchaloei@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:04:23 by tchaloei          #+#    #+#             */
/*   Updated: 2024/08/14 18:04:23 by tchaloei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				data;
	int				position;
	int				binary;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	struct s_list	*top_a;
	struct s_list	*top_b;
	int				count;
	int				divide;
	int				mid_divide;
	int				mid;
	int				pos;
	int				range;
}	t_stack;
/*-------push_swap-------*/
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
/*-------rotate_reverse-------*/
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	reverse_a(t_stack *stack);
void	reverse_b(t_stack *stack);
/*-------sorting_stack-------*/
void	sorting_stack(t_stack *stack);
void	sort3_stack_a(t_stack *stack);
void	four_plus(t_stack *stack);
void	four_plus_extend(t_stack *stack);
/*-------tool_extend-------*/
int		sort_stack(t_stack *stack);
int		count_stack_a(t_stack *stack);
int		count_stack_b(t_stack *stack);
int		find_position(t_stack *stack, int data);
int		find_max(t_stack *stack);
/*-------sort_four-------*/
void	push_return(t_stack *stack);
void	push_return2(t_stack *stack, int max);
void	sort_more_four1(t_stack *stack);
void	sort_more_four2(t_stack *stack);
void	sort_more_four3(t_stack *stack);
/*-------utils-------*/
long	ft_atol(const char *str);
size_t	ft_strlen(const char *str);
int		itobi(int value);
/*-------check_int-------*/
void	check_int(char **av);
void	check_equal_to_zero(char *av);
void	check_string(char *str);
void	check_repeat(t_stack *stack);
void	msg_error(int n);
/*-------pushint_free-------*/
void	pushing_int(int ac, char **av, t_stack	*stack);
void	pushing_inside(t_stack *stack, char *num);
int		count_str(char *str);
void	push_stack_a(t_stack *stack, int value);
void	freestack(t_stack *stack);
/*-------sort_four2-------*/
void	sort_more_four4(t_stack *stack);
void	sort_more_four5(t_stack *stack);
void	sort_more_four6(t_stack *stack);
/*-------radix_sort-------*/
void	redix_sort(t_stack *stack);
void	get_binary(t_stack *stack);

#endif