/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:39:11 by diomende          #+#    #+#             */
/*   Updated: 2025/05/01 17:01:59 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (ft_putstr("(null)"));
	i = 0;
	while (s[i])
		i+= ft_putchar(s[i]);
	return (i);
}
