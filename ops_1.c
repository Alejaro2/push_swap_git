/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:17:27 by alejaro2          #+#    #+#             */
/*   Updated: 2025/02/26 19:39:41 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void double_swap(t_stack *a, t_stack *b)
{
	swap(a, 'a', 0);
	swap(b, 'b', 0);
	write(1, "ss\n", 3);
}
void	double_rotate(t_stack *a, t_stack *b)
{
	rotate(a, 'a', 0); 
	rotate(b, 'b', 0); 
	write(1, "rr\n", 3);
}
void	double_reverse_rotate(t_stack *a, t_stack *b)
{
	reverse_rotate(a, 'a', 0);
	reverse_rotate(b, 'b', 0); 
	write(1, "rrr\n", 4);
}