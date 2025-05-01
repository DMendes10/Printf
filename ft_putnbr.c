/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:36:20 by diomende          #+#    #+#             */
/*   Updated: 2025/05/01 14:51:33 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_putnbr2(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr (147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
		ft_putnbr (n);
	}
	else if (n > 9)
	{
		ft_putnbr (n / 10);
		ft_putnbr (n % 10);
	}
	else
		ft_putchar (n + 48);
}

int	ft_putnbr(int n)
{
	int				count;
	unsigned int	i;

	i = (unsigned int) n;
	count = 0;
	if (n < 0)
	{
		i = -1 * i;
		count++;
	}
	while (i > 0)
	{
		i = (i / 10);
		count++;
	}
	ft_putnbr2 (n);
	return (count);
}
