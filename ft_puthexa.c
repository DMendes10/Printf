/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:44:10 by diomende          #+#    #+#             */
/*   Updated: 2025/05/03 19:45:19 by diogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_puthexa(unsigned int n, char c)
{
	int		base;
	int 	i;
	char	*set;

	i = 0;
	base = 16;
	if (c == 'x')
		set = "0123456789abcdef";
	else if (c == 'X')
		set = "0123456789ABCDEF";
	if (n >= base)
		i += ft_puthexa (n / base, c);
	i += ft_putchar (set [n % base]);
	return (i);
}
