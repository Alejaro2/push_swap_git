/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:01:42 by alejaro2          #+#    #+#             */
/*   Updated: 2025/02/28 13:33:20 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *create_node(int value, int index)
{
	t_node *node = malloc(sizeof(t_node));
	if(!node)
		return(NULL);
	node->value = value;
	node->s_index = index;
	node->next = NULL;
	
	return node;
}


t_stack *create_stack(void)
{
	t_stack *stack = malloc(sizeof(t_stack));
	if (!stack)
		return(NULL);
		
	stack->top = NULL;
	stack->size = 0;
	return stack;
}

void lstadd(t_stack *stack, int value, int index)
{
	t_node *new_node; 

	new_node = create_node(value, index);
	
	if(!new_node)
		return;
	
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

void free_stack(t_stack *stack)
{
	t_node *temp;

	if(!stack)
		return;
	while (stack->top)
	{
		temp = stack->top;
		stack->top = stack->top->next;
		free(temp);
	}
	free(stack);
}
void print_stack(t_stack *stack)
{
	t_node *current;
	
	current = stack->top;
	while(current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}
