/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:41:38 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/02 21:59:56 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void set_algorithm(t_stack *stack_a, t_stack *stack_b, int size)
{
	if(size == 2)
		swap(stack_a, 'a', 1);
	else if(size == 3)
		simple_sort(stack_a, 3);
	else if(size <= 7)
		insertion_sort(stack_a, stack_b, size);
	else if(size > 7)
	{
		k_sort1(stack_a, stack_b, size);
		k_sort2(stack_a, stack_b, size);
	}
}

static void init_stack_values(t_stack *stack, int *numbers, int count)
{
	int i;

	i = count - 1;
	while (i >= 0)
	{
		lstadd(stack, numbers[i], i);
		i--;
	}
}
t_stack *process_stack(int *numbers, int count)
{
	t_stack *stack_a;
	
	stack_a = create_stack();
	if(!stack_a)
		return(NULL);
	init_stack_values(stack_a, numbers, count);
	return(stack_a);
}

void assign_index(t_stack *stack_a, int *numbers, int count)
{
	t_node *temp;
	
	ft_bubblesort(numbers, count);
	temp = stack_a->top;
	while (temp)
	{
		temp->s_index = ft_index(numbers, temp->value);
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	int	count;
	int	*numbers;
	t_stack *stack_a;
	t_stack *stack_b;
	
	if (argc <= 2)
		return(0);
	count = valid_digits(argc, argv);
	numbers = convert_init(argc, argv, count);
	is_sorted(numbers, count);
	duplicate(numbers, count);
	stack_a = process_stack(numbers, count);
	stack_b = create_stack();
	if(!stack_a || !stack_b)
		return(free(numbers), free_stack(stack_a), free_stack(stack_b), 1);
	assign_index(stack_a, numbers, count);
	set_algorithm(stack_a, stack_b, count);
	free_stack(stack_a);
	free_stack(stack_b);
	free(numbers);
	return (0);
}





