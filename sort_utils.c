/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:50:50 by alejaro2          #+#    #+#             */
/*   Updated: 2025/02/27 14:18:44 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_node(t_stack *stack, int *value, int *index)
{
	t_node	*first;

	if (!stack || !stack->top)
	{
		*value = 0;
		*index = 0;
		return ;
	}
	first = stack->top;
	*value = first->value;
	*index = first->s_index;
	stack->top = first->next;
	free(first);
	stack->size--;
}
void	ft_bubblesort(int *array, int count)
{
	int	i;
	int	temp;
	int	swapped;

	if (!array || count <= 1)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < count - 1)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
		count--;
	}
}
int	ft_index(int *array, int n)
{
	int	i;

	i = 0;
	while (array[i] != n)
		i++;
	return (i);
}
int find_min_index(t_stack *stack)
{
	t_node *current;
	int min;

	if(!stack || !stack->top)
		return(-1);
	current = stack->top;
	min = current->s_index;
	while(current)
	{
		if(current->s_index < min)
			min = current->s_index;
		current = current->next;
	}
	return(min);
}
int count_index(t_node *node, int index)
{
	int counter;

	if(!node)
		return(-1);
	counter = 0;
	while(node)
	{
		if(node->s_index == index)
			return(counter);
		node = node->next;
		counter++;
	}
	return(0);
}
