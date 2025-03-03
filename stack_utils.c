/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:20:20 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/03 11:29:13 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack *stack)
{
	t_node	*tmp;

	if (!stack || !stack->top || !stack->top->next)
		return (1);
	tmp = stack->top;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
void	sort(t_stack *a, t_stack *b, int len)
{
	if (is_stack_sorted(a))
	{
		free_stack(a);
		free_stack(b);
		exit(0);
	}
	if (len == 2)
	{
		if (a->top->value > a->top->next->value)
			swap(a, 'a', 1);
	}
	else if (len == 3)
		simple_sort(a, len);
}
int	is_rot_sort(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->top->value;
	b = stack->top->next->value;
	c = stack->top->next->next->value;
	if (a < b && b < c)
		return (1);
	if (b < c && a > c)
		return (1);
	if (c < a && a < b)
		return (1);
	return (0);
}
void	simple_sort(t_stack *stack, int len)
{
	int	min;
	int	pos;

	if (is_stack_sorted(stack))
		return ;
	min = find_min_index(stack);
	pos = count_index(stack->top, min);
	if (is_rot_sort(stack))
	{
		if (pos < len - pos)
			rotate(stack, 'a', 1);
		else
			reverse_rotate(stack, 'a', 1);
	}
	else
	{
		swap(stack, 'a', 1);
		if (is_stack_sorted(stack))
			return ;
		else if(pos < len - pos)
			rotate(stack, 'a', 1);
		else
			reverse_rotate(stack, 'a', 1);
	}
}
void insertion_sort(t_stack *a, t_stack *b, int len)
{
	int min;
	int remaining;

	remaining = len - 3;
	while (remaining--)
	{
		min = find_min_index(a);
		while (a->top->s_index != min)
		{
			if(count_index(a->top, min) <= a->size / 2)
				rotate(a, 'a', 1);
			else
				reverse_rotate(a, 'a', 1);
		}
		push(a, b, 'b', 1);
	}
	simple_sort(a, 3);
	while(b->size > 0)
		push(b, a, 'a', 1);
}
