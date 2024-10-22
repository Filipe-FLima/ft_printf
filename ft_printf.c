/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:42:17 by flima             #+#    #+#             */
/*   Updated: 2024/10/22 18:10:27 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_conversion(va_list args, const char *format)
{
	int	n;
	
	n = 0;
	if (*format == '\0')
		return (-1);
	else if (*format == '%')
		n = ft_putchar_n('%');
	else if (*format == 'c')
		n = ft_putchar_n(va_arg(args, int));
	else if (*format == 's')
		n = ft_putstr_n(va_arg(args, char *));
	else if (*format == 'i' || *format == 'd')
		n = ft_putnbr_n(va_arg(args, int));
	else if (*format == 'u')
		n = ft_putuns_n(va_arg(args, unsigned int));
	else if (*format == 'p')
		n = ptr_tohex(va_arg(args, unsigned long));
	else if (*format == 'X' || *format == 'x')
		n = dec_tohex((va_arg(args, int)), format);
	return (n);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_start(args, format);
	unsigned int	count;
	int				verifier;

	if (!format)
		return (0);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			verifier = print_conversion(args, format);
			if(verifier > -1)
				count += verifier;
			else
				return (-1);
		}
		else
			count += ft_putchar_n(*format);
		format++;
	}
	va_end(args);
	return (count);
}

int main()
{
    // char    *p = "string";
    int     original;
    int     my_len;
	
    // original = printf("%p%p%p\n", &p, &p, &p);
    // my_len = ft_printf("%p%p%p\n", &p, &p, &p);
    // printf("this is original %d,this is my %d\n", original, my_len);
    // original = printf("%c%c%d%c\n", 'a', 'b', 3, '%');
    // my_len = ft_printf("%c%c%d%c\n", 'a', 'b', 3, '%');
    // printf("this is original %d,this is my %d\n", original, my_len);
    // ft_printf("%c%c%d%s\n", 'a', 'b', 3, "bla");
    // ft_printf("ble%c%c%i%sbla%%%x\n", 'a', 'b', 120, "foo", -5151);
    // // ft_printf("%%\n");
    // ft_printf("ble%c%c%i%sbla%%%X\n", 'a', 'b', 120, "foo", -5151);
    // printf("%%\n");
    // printf("%d\n", printf("hello"));
    // ft_printf("%d\n", ft_printf("hello"));
    // original = printf("%\0 ujruiturtiyut\n");
    // my_len = ft_printf("%\0 ujruiturtiyut\n");
    // printf("%d\n", my_len);
    // int original = printf("%%%"); //someone fail me because this test, and there is a warning!
    // original = ft_printf("%%%kk");
    // printf("this is original %d", original);
    // original = printf("%p\n", NULL);
    // my_len = ft_printf("%p\n", NULL); //minha filipe retorna 0x0 - deveria retornar nill?
    // printf("this is original %d,this is my %d\n", original, my_len);
    // original = printf("%s\n", NULL);
    // my_len = ft_printf("%s\n", NULL);
    // printf("this is original %d", my_len);
    original = printf("%%%%%c%%%c%%%%%s%%%%%d%%%%%%%i\n", 'a', 'b', "Integer quis blandit ligula, nec fermentum elit. Cras pretium neque sed elit volutpat commodo. Quisque vitae odio et dui consectetur interdum. Praesent et fringilla elit. Integer rutrum auctor lorem, vel blandit quam convallis eget. Integer faucibus placerat tempor. Ut sed sem viverra, ultrices dolor in, placerat eros. In finibus mi aliquet turpis aliquet, eu aliquam orci vehicula", 10, 1994);
    my_len = ft_printf("%%%%%c%%%c%%%%%s%%%%%d%%%%%%%i\n", 'a', 'b', "Integer quis blandit ligula, nec fermentum elit. Cras pretium neque sed elit volutpat commodo. Quisque vitae odio et dui consectetur interdum. Praesent et fringilla elit. Integer rutrum auctor lorem, vel blandit quam convallis eget. Integer faucibus placerat tempor. Ut sed sem viverra, ultrices dolor in, placerat eros. In finibus mi aliquet turpis aliquet, eu aliquam orci vehicula", 10, 1994);
    printf("this is original %d,this is my %d", original, my_len);
}