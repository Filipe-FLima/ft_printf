/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:01:45 by flima             #+#    #+#             */
/*   Updated: 2024/10/22 17:25:24 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static int	str_hexsize(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	ptr_tohex(unsigned long nbr)
{
	int		size;
	char	*str;
	char	*hex;


	size = str_hexsize(nbr);
	hex = "0123456789abcdef";
	str = (char *)malloc((size + 3) * sizeof(char));
	if (str == NULL)
		return (-1);
	str[0] = '0';
	str[1] = 'x';
	str[size + 2] = '\0';
	while (size > 0)
	{
		str[size + 1] = hex[nbr % 16];
		nbr = nbr / 16;
		size--;
	}
	size = ft_putstr_n(str);
	free(str);
	return (size);
}

static char	*nbr_tohex(unsigned int	nbr, const char *hex)
{
	int		len;
	char	*str;
	char	*hex_temp;

	hex_temp = (char *)hex;
	len = str_hexsize(nbr);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		len--;
		str[len] = hex_temp[nbr % 16];
		nbr = nbr / 16;
	}
	return (str);
}

int	dec_tohex(unsigned int n, const char *chr)
{
	char			*hex_base;
	char			*hex;
	unsigned int	len;

	if (*chr == 'X')
		hex_base = "0123456789ABCDEF";
	else if (*chr == 'x')
		hex_base = "0123456789abcdef";
	if (n == 0)
		return (ft_putchar_n(*chr));
	hex = nbr_tohex(n, hex_base);
	if (hex == NULL)
		return (-1);
	len = ft_putstr_n(hex);
	free(hex);
	return (len);
}

// int main(void)
// {
// 	int i;
// 	const char *c = "Xtt";
	
// 	i = dec_tohex(7921315, c);
// 	printf("\n%d", i);
// 	return 0;
// }