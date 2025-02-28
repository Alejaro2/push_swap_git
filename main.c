/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:41:38 by alejaro2          #+#    #+#             */
/*   Updated: 2025/02/28 18:36:30 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void init_stack_values(t_stack *stack, int *numbers, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		lstadd(stack, numbers[i], i);
		i++;
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

int	main(int argc, char **argv)
{
	int	count;
	int	*numbers;
	t_node *temp;
	t_stack *stack_a;
	
	if (argc < 2)
		return(0);
	count = valid_digits(argc, argv);
	numbers = convert_init(argc, argv, count);
	duplicate(numbers, count);

	stack_a = process_stack(numbers, count);
	ft_bubblesort(numbers, count);
	temp = stack_a->top;
	while (temp)
	{
		temp->s_index = ft_index(numbers, temp->value);
		temp = temp->next;
	}
	if(stack_a->size == 3)
		simple_sort(stack_a, stack_a->size);
	if(stack_a)
	{
		print_stack(stack_a);
		free_stack(stack_a);
	}
	free(numbers);
	return (0);
}




