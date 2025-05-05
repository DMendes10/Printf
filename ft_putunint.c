/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:59:43 by diomende          #+#    #+#             */
/*   Updated: 2025/05/05 12:55:24 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"



int	ft_putunint(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += ft_putunint (n / 10);
		i += ft_putunint (n % 10);
	}
	else
		i += ft_putchar (n + 48);
	return (i);
}

// int	ft_putunint(unsigned int n)
// {
// 	int				count;
// 	unsigned int	i;

// 	i = n;
// 	count = 0;
// 	while (i > 0)
// 	{
// 		i = (i / 10);
// 		count++;
// 	}
// 	ft_putunint2 (n);
// 	return (count);
// }