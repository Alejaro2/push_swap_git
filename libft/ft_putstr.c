/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:14:39 by alejaro2          #+#    #+#             */
/*   Updated: 2025/01/17 16:08:00 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *s)
{
	while (*s)
		write(1, (s++), 1);
}
/*int main()
{
	char p[] = "holartf";
	int fd = open("prueba", O_CREAT | O_WRONLY, 0777);
	ft_putstr_fd(p, fd);
}*/
