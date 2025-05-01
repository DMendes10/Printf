/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexaup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:44:10 by diomende          #+#    #+#             */
/*   Updated: 2025/05/01 19:43:00 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_puthexa(unsigned int n, char c)
{
	int		base;
	int		i;
	char	*set;

	base = 16;
	if (c == 'x')
		set = "0123456789abcdef";
	else if (c == 'X')
		set = "0123456789ABCDEF";
	if (n < base)
		return (putchar(set[n]));
	while (n >= base)
	{
		i += ft_puthexa (n / base, c);
		i += ft_puthexa (n % base, c);
	}
	i += ft_putchar (set[n]);
	return (i);
}
