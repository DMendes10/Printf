/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:36:26 by diomende          #+#    #+#             */
/*   Updated: 2025/05/03 19:15:42 by diogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_choose_format(char c, va_list args);
int		ft_putnbr(int n);
int		ft_putunint(unsigned int n);
int		ft_puthexa(unsigned int n, char c);
int	    ft_putpointer(void *ptr, int base, char *set, unsigned int loopstoper);

#endif