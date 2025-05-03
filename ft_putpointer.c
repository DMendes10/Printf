/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:46:41 by diomende          #+#    #+#             */
/*   Updated: 2025/05/03 19:18:45 by diogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putpointer(void *ptr, int base, char *set, unsigned int loopstoper)
{
	int		i;
	unsigned long long	plong;
	
	i = 0;
	plong = (unsigned long long) ptr;
	if (!ptr)
		return (write (1, "(nil)", 5));
	if (loopstoper == 0)
		i += write (1, "0x", 2);
	// if (plong < base)
	// 	return (putchar(set[plong]));
	if (plong >= base)
	{
		i += ft_putpointer ((void *)(plong / base), base, set, loopstoper + 1);
		// i += ft_putpointer ((void *)(plong % base), base, set);
	}
	i += ft_putchar (set[plong % base]);
	return (i);
}
