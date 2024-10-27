/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:42:17 by flima             #+#    #+#             */
/*   Updated: 2024/10/27 18:09:38 by flima            ###   ########.fr       */
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
		n = ft_putunsig_n(va_arg(args, unsigned int));
	else if (*format == 'p')
		n = ptr_tohex(va_arg(args, uintptr_t));
	else if (*format == 'X' || *format == 'x')
		n = dec_tohex((va_arg(args, int)), format);
	return (n);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	count;
	int				verifier;

	va_start(args, format);
	if (!format)
		return (0);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			verifier = print_conversion(args, format);
			if (verifier > -1)
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

// int	main(void)
// {
// 	int	size;
// 	int	size1;
// 	char *s = NULL;

// 	size = printf("%s%p%u%x%X%%%c\n", s, NULL, 0, 0, 0, 'a');
// 	size1 = ft_printf("%s%p%u%x%X%%%c\n", s, NULL, 0, 0, 0, 'a');
// 	printf("%d\n%d", size, size1);
// 	return 0;
// }