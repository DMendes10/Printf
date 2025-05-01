/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:59:43 by diomende          #+#    #+#             */
/*   Updated: 2025/05/01 16:18:01 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"



static void	ft_putunint2(unsigned int n)
{
	if (n > 9)
	{
		ft_putunint2 (n / 10);
		ft_putunint2 (n % 10);
	}
	else
		ft_putchar (n + 48);
}

int	ft_putunint(unsigned int n)
{
	int				count;
	unsigned int	i;

	i = n;
	count = 0;
	while (i > 0)
	{
		i = (i / 10);
		count++;
	}
	ft_putunint2 (n);
	return (count);
}