/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:41:21 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/04 10:02:02 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_error(char *str, int flag)
{
	ft_putstr(str);
	exit(flag);
}

int is_sorted(int *numbers, int count)
{
	int	i;

	i = 0;
	while (i < (count - 1))
	{
		if (numbers[i] > numbers[i + 1])
			return(0);
		i++;
	}
	free(numbers);
	exit(0);
}

int	is_all_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	duplicate(int *numbers, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < (count - 1))
	{
		j = i + 1;
		while (j < count)
		{
			if (numbers[i] == numbers[j])
			{
				free(numbers);
				ft_error("Error\n", 1);
			}
			j++;
		}
		i++;
	}
}