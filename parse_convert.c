/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:34:48 by alejaro2          #+#    #+#             */
/*   Updated: 2025/03/04 10:02:14 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_free_mem(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	else
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}

int	*save_mem(int count)
{
	int	*numbers;

	numbers = malloc(sizeof(int) * count);
	if (!numbers)
		ft_error("Error\n", 1);
	return (numbers);
}

void	convert_numbers(char **split, int *numbers, int *new)
{
	int	j;

	j = 0;
	while (split[j])
	{
		numbers[*new] = ft_atoi(split[j]);
		(*new)++;
		j++;
	}
	ft_free_mem(split);
}

int	*convert_init(int argc, char **argv, int count)
{
	int		*numbers;
	char	**split;
	int		i;
	int		new;

	new = 0;
	numbers = save_mem(count);
	if(!numbers)
		return NULL;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
		{
			free(numbers);
			ft_error("Error\n", 1);
		}	
		convert_numbers(split, numbers, &new);
		i++;
	}
	return (numbers);
}



