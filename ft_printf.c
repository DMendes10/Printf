int ft_format(char *s)
{
    int i;
    int count;

    i = 0;
    if (s[i] == '%')
        count = ft_putchar ('%');
    if (s[i] == 's')
        count = ft_putstr (va_args (args, char*));
    else if (s[i] == 'c')
        count = ft_putchar (va_arg (args, char));
    else if (s[i] == 'd')
        count = ft_putnbr(va_args (args, int));
    else if (s[i] == 'u')
        count = ft_putnbr(va_args (args, unsigned int));
    else if (s[i] == 'p')
        count = ????
    else if (s[i] == 'x')
        count = ????
    else if (s[i] == 'X')
        count = ????
    else if (s[i] == 'i')
        count = ????
    return (count);
}
