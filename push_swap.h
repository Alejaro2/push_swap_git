/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:31:30 by alejaro2          #+#    #+#             */
/*   Updated: 2025/02/28 18:25:18 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int value;
	int s_index;
	struct s_node *next;
} t_node;

typedef struct s_stack {
	t_node *top;
	int size;
} t_stack;


int is_valid_char(char c, int position);
int valid_digits(int argc, char **argv);
int valid_limits(char *str);
void validate(char *split_str);
void duplicate(int *numbers, int count);
int is_sorted(int *numbers, int count);

void ft_free_mem(char **array);
int *save_mem(int count);
void free_stack(t_stack *stack);
void print_stack(t_stack *stack);


void convert_numbers(char **split, int *numbers, int *new);
int *convert_init(int argc, char **argv, int count);

void ft_error(char *str, int flag);
int is_all_spaces(char *str);

void	reverse_rotate(t_stack *stack, char x, int b);
void	rotate(t_stack *stack, char x, int b);
void	push(t_stack *src, t_stack *dst, char x, int b);
void	swap(t_stack *stack, char x, int b);

t_node *create_node(int value, int index);
t_stack *create_stack(void);
void lstadd(t_stack *stack, int value, int i);
void del_node(t_stack *stack, int *value, int *index);
void	ft_bubblesort(int *array, int count);
int	ft_index(int *array, int n);
int find_min_index(t_stack *stack);
int count_index(t_node *node, int index);

void insertion_sort(t_stack *a, t_stack *b, int len);
void	simple_sort(t_stack *stack, int len);
int	is_rot_sort(t_stack *stack);
void	sort(t_stack *a, t_stack *b, int len);
int	is_stack_sorted(t_stack *stack);
void k_sort2(t_stack *a, t_stack *b, int len);
void k_sort1(t_stack *a, t_stack *b, int len);
int ft_sqrt(int nmb);


#endif