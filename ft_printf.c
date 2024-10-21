/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:42:17 by flima             #+#    #+#             */
/*   Updated: 2024/10/21 20:41:27 by flima            ###   ########.fr       */
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
		n += ft_putchar_n('%');
	else if (*format == 'c')
		n += ft_putchar_n(va_arg(args, int));
	else if (*format == 's')
		n += ft_putstr_n(va_arg(args, char *));
	else if (*format == 'i' || *format == 'd')
		n += ft_putnbr_n(va_arg(args, int));
	else if (*format == 'u')
		n += ft_putuns_n(va_arg(args, unsigned int));
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
int	main(void)
{
	char	c = 'A';
	char name1[] = "Mateus";
	int 	i = INT_MIN;
	unsigned int usi = 1294967295;
	
	i = ft_printf("%s\n%c\n%d\n%u", name1, c, i, usi);
	write(1, "\n", 1);
	printf("%d", i);
	return (0);
}