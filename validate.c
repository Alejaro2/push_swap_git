/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:01:50 by alejaro2          #+#    #+#             */
/*   Updated: 2025/02/23 20:38:36 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/libft.h"
#include "push_swap.h"

int	valid_limits(char *str)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str);
	if (len == 0)
		return (0);
	if (str[i] == '-')
	{
		i++;
		while (str[i] == '0')
			i++;
		if ((len - i) > 10 || ((len - i) == 10 && ft_strncmp(str + i,
					"2147483648", 10) > 0))
			return (0);
	}
	else
	{
		while (str[i] == '0')
			i++;
		if ((len - i) > 10 || ((len - i) == 10 && ft_strncmp(str + i,
					"2147483647", 10) > 0))
			return (0);
	}
	return (1);
}
int	is_valid_char(char c, int position)
{
	if (position == 0 && (ft_isdigit(c) || c == ' ' || c == '+' || c == '-'))
		return (1);
	else if (position > 0 && ft_isdigit(c))
		return (1);
	return (0);
}
int	process_and_validate(char *arg)
{
	char	**split;
	int		j;
	int		count;

	if (is_all_spaces(arg) || arg[0] == '\0')
		ft_error("Error\n", 1);
	split = ft_split(arg, ' ');
	if (!split)
		ft_error("Error\n", 1);
	j = 0;
	count = 0;
	while (split[j])
	{
		validate(split[j]);
		count++;
		j++;
	}
	ft_free_mem(split);
	return (count);
}

int	valid_digits(int argc, char **argv)
{
	int	i;
	int	total_count;

	i = 1;
	total_count = 0;
	while (i < argc)
	{
		total_count += process_and_validate(argv[i]);
		i++;
	}
	return (total_count);
}


void	validate(char *split_str)
{
	int	i;

	i = 0;
	while (split_str[i] == ' ')
		i++;

	if ((split_str[i] == '-' || split_str[i] == '+') && split_str[i + 1] == '\0')
		ft_error("Error\n", 1);

	while (split_str[i])
	{
		if (!is_valid_char(split_str[i], i))
			ft_error("Error\n", 1);
		i++;
	}
	if (!valid_limits(split_str))
		ft_error("Error\n", 1);
}

