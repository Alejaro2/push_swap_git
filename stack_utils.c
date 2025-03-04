/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:20:20 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/04 17:50:27 by alejaro2         ###   ########.fr       */
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
			rotate(stack, 'a');
		else
			reverse_rotate(stack, 'a');
	}
	else
	{
		swap(stack, 'a');
		if (is_stack_sorted(stack))
			return ;
		else if(pos < len - pos)
			rotate(stack, 'a');
		else
			reverse_rotate(stack, 'a');
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
				rotate(a, 'a');
			else
				reverse_rotate(a, 'a');
		}
		push(a, b, 'b');
	}
	simple_sort(a, 3);
	while(b->size > 0)
		push(b, a, 'a');
}
