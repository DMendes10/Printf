/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:19:15 by diomende          #+#    #+#             */
/*   Updated: 2025/05/05 15:20:38 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int ft_format_validator(char c)
{
	if (c == '%')
		return (1);
	else if (c == 's')
		return (1);
	else if (c == 'c')
		return (1);
	else if (c == 'd')
		return (1);
	else if (c == 'u')
		return (1);
	else if (c == 'p')
		return (1);
	else if (c == 'x')
		return (1);
	else if (c == 'X')
		return (1);
	else if (c == 'i')
		return (1);
	else
		return (0);
}

static int	ft_choose_format(char c, va_list args)
{
	if (c == '%')
		return (ft_putchar ('%'));
	else if (c == 's')
		return (ft_putstr (va_arg(args, char *)));
	else if (c == 'c')
		return (ft_putchar (va_arg(args, int)));
	else if (c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunint(va_arg (args, unsigned int)));
	else if (c == 'p')
		return (ft_putpointer(va_arg (args, void *), 16, "0123456789abcdef", 0));
	else if (c == 'x')
		return (ft_puthexa(va_arg (args, unsigned int), c));
	else if (c == 'X')
		return (ft_puthexa(va_arg (args, unsigned int), c));
	else if (c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	unsigned int	i;
	unsigned int	counter;
	
	if (!s)
		return (-1);
	va_start (args, s);
	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (!(ft_format_validator(s[i + 1])))
				return (-1);
			counter += ft_choose_format(s[i + 1], args);
			i++;
		}
		else
			counter += ft_putchar (s[i]);
		i++;
	}
	va_end (args);
	return (counter);
}


#define FAIL "****************** TEST FAILED *********************\n\n"

int	main(void)
{
	// char *c = "ola";
	// int d = 2147483647;
	// int d1 = -2147483648;
	// int d2 = 0;
	// int hexa = 123456789;

	// printf("%d\n", printf("\nhello %"));
	// ft_printf("%d\n",ft_printf("\nhello %"));

	// printf("%d\n", printf("\nhello %s", -1));
	// ft_printf("%d\n",ft_printf("\nhello %s", -1));
	

	// printf(" printf out\n%d printf length\n", printf(" %d %i %d %i", INT_MAX, INT_MIN, 0, -42));
	// printf(" ft_printf out\n%d ft_printf length\n", ft_printf(" %d %i %d %i", INT_MAX, INT_MIN, 0, -42));
	
	// printf(" printf out\n%d printf length\n", printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%\
	// 		%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%\
	// 		%c%%", 'A', "42", 42, 42, 42, 42, 42, 'B', "-42", -42, -42, -42,\
	// 		-42, 42, 'C', "0", 0, 0, 0, 0, 42, 0));
	// printf(" ft_printf out\n%d ft_printf length\n", ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%\
	// 		%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%\
	// 		%c%%", 'A', "42", 42, 42, 42, 42, 42, 'B', "-42", -42, -42, -42,\
	// 		-42, 42, 'C', "0", 0, 0, 0, 0, 42, 0));

	// void *ptr = (void *)0x1234abcd;
	// unsigned int hex = 305441741; // 0x1234ABCD

	// ft_printf("Pointer: %p\n", ptr);
	// ft_printf("Hex lower: %x\n", hex);
	// ft_printf("Hex upper: %X\n", hex);

	// printf("Pointer: %p\n", ptr);
	// printf("Hex lower: %x\n", hex);
	// printf("Hex upper: %X\n", hex);
	
	
// 	int		a;
// 	int		b;
// 	char	*s;

// 	// x tests
// 	printf("x tests\n");
// 	printf(" printf out\n%d printf length\n", a = printf("%x", 0));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x", 0));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf("%x", -1));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x", -1));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf("%x", 1));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x", 1));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf("%x", 10));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x", 10));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf("%x", 99));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x", 99));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf("%x", -101));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x", -101));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf("%x", INT_MAX));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x",
// 			INT_MAX));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf("%x", INT_MIN));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x",
// 			INT_MIN));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf("%x", UINT_MAX));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x",
// 			UINT_MAX));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf("%x %x %x %x", INT_MAX,
// 			INT_MIN, 0, -42));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x %x %x %x",
// 			INT_MAX, INT_MIN, 0, -42));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	// X tests
// 	printf("X tests\n");
// 	printf(" printf out\n%d printf length\n", a = printf("%X", 0));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X", 0));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf("%X", -1));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X", -1));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf("%X", 1));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X", 1));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf("%X", 10));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X", 10));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf("%X", 99));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X", 99));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf("%X", -101));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X", -101));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf("%X", INT_MAX));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X",
// 			INT_MAX));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf("%X", INT_MIN));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X",
// 			INT_MIN));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf("%X", UINT_MAX));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X",
// 			UINT_MAX));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf("%X %X %X %X", INT_MAX,
// 			INT_MIN, 0, -42));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X %X %X %X",
// 			INT_MAX, INT_MIN, 0, -42));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	// c tests
// 	printf("c tests\n");
// 	printf(" printf out\n%d printf length\n", a = printf("%c", '0'));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%c", '0'));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf(" %c", '0'));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %c", '0'));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf("%c ", '0'));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%c ", '0'));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf(" %c ", '0'));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %c ", '0'));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf(" %c", '0' - 256));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %c", '0'
// 			- 256));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf("%c ", '0' + 256));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%c ", '0'
// 			+ 256));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf(" %c %c %c ", '1', '2',
// 			'3'));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %c %c %c ",
// 			'1', '2', '3'));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	// d & i tests
// 	printf("d & i tests\n");
// 	printf(" printf out\n%d printf length\n", a = printf(" %d ", -99));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %d ", -99));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf(" %d ", 100));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %d ", 100));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf(" %d ", INT_MAX));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %d ",
// 			INT_MAX));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf(" %d ", INT_MIN));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %d ",
// 			INT_MIN));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf(" %d ", UINT_MAX));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %d ",
// 			UINT_MAX));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf(" %d %i %d %i", INT_MAX, INT_MIN, 0, -42));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %d %i %d %i", INT_MAX, INT_MIN, 0, -42));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// {	// p tests
// 	printf("p tests\n");
// 	printf(" printf out\n%d printf length\n", a = printf(" %p ", (void *)-1));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %p ",
// 			(void *)-1));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf(" %p ", (void *)1));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %p ",
// 			(void *)1));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf(" %p ", (void *)15));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %p ",
// 			(void *)15));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf(" %p ", (void *)0));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %p ",
// 			(void *)0));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf("p tests\n");
// 	printf(" printf out\n%d printf length\n", a = printf(" %p ", NULL));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %p ",
// 			NULL));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf(" %p %p ",
// 			(void *)LONG_MIN, (void *)LONG_MAX));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %p %p ",
// 			(void *)LONG_MIN, (void *)LONG_MAX));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf(" %p %p ",
// 			(void *)INT_MIN, (void *)INT_MAX));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %p %p ",
// 			(void *)INT_MIN, (void *)INT_MAX));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf(" %p %p ",
// 			(void *)ULONG_MAX, (void *)-ULONG_MAX));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %p %p ",
// 			(void *)ULONG_MAX, (void *)-ULONG_MAX));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	// s tests
// 	s = "this is a longer test string to test printf";
// 	printf("s tests\n");
// 	printf(" printf out\n%d printf length\n", a = printf("%s", ""));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%s", ""));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf(" %s %s ", "", "-"));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %s %s ", "",
// 			"-"));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf(" %s %s %s %s %s", "\
// 			- ", "", "4", "", s));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %s %s %s %s\
// 			%s", " - ", "", "4", "", s));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	// u tests
// 	printf("u tests\n");
// 	printf(" printf out\n%d printf length\n", a = printf(" %u ", -100));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %u ",
// 			-100));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf(" %u ", INT_MAX));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %u ",
// 			INT_MAX));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf(" %u ", INT_MIN));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %u ",
// 			INT_MIN));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	printf(" printf out\n%d printf length\n", a = printf(" %u ", UINT_MAX));
// 	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %u ",
// 			UINT_MAX));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// 	// mix tests
// 	printf("mix tests\n");
// 	printf(" printf out\n%d printf length\n",
// 		a = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%\
// 			%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%\
// 			%c%%", 'A', "42", 42, 42, 42, 42, 42, 'B', "-42", -42, -42, -42,\
// 			-42, 42, 'C', "0", 0, 0, 0, 0, 42, 0));
// 	printf(" ft_printf out\n%d ft_printf length\n",
// 		b = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%\
// 			%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%\
// 			%c%%", 'A', "42", 42, 42, 42, 42, 42, 'B', "-42", -42, -42, -42,\
// 			-42, 42, 'C', "0", 0, 0, 0, 0, 42, 0));
// 	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);
// }
}
