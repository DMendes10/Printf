/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:46:41 by diomende          #+#    #+#             */
/*   Updated: 2025/05/01 19:39:22 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putpointer(void *ptr, int base, char *set)
{
	int		i;
	unsigned long long	plong;
	
	i = 0;
	plong = (unsigned long long) ptr;
	if (!ptr)
		return (write (1, "(nill)", 6));
	i += write (1, "0x", 2);
	if (plong < base)
		return (putchar(set[plong]));
	while (plong >= base)
	{
		i += ft_putpointer ((void *)(plong / base), base, set);
		i += ft_putpointer ((void *)(plong % base), base, set);
	}
	i += ft_putchar (set[plong]);
	return (i);
}
