/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:11:13 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/04 17:51:14 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

 int ft_sqrt(int nmb)
 {
	int i;

	if(nmb < 0)
		return(-1);
	if(nmb < 4)
		return(1);
	i = 2;
	while(i * i < nmb)
		i++;
	if(i * i - nmb < nmb - (i - 1) * (i - 1))
		return(i);
	return(i - 1);
 }

 void k_sort1(t_stack *a, t_stack *b, int len)
 {
	int i;
	int range;

	i = 0;
	range = ft_sqrt(len) * 14 / 10;
	while(a->top)
	{
		if(a->top->s_index <= i)
		{
			push(a, b, 'b');
			i++;
		}
		else if(a->top->s_index <= i + range)
		{
			push(a, b, 'b');
			rotate(b, 'b');
			i++;
		}
		else
			rotate(a, 'a');
	}
 }
 
 void k_sort2(t_stack *a, t_stack *b, int len)
 {
	while(len--)
	{
		if(count_index(b->top, len) <= b->size / 2)
		{
			while(b->top->s_index != len)
				rotate(b, 'b');
		}
		else
		{
			while(b->top->s_index != len)
				reverse_rotate(b, 'b');
		}
		push(b, a, 'a');
	}
 }