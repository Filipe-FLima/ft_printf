/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:07:27 by flima             #+#    #+#             */
/*   Updated: 2024/10/24 15:44:39 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./Libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_putchar_n(int c);
int	ft_putstr_n(char *s);
int	ft_putnbr_n(int nb);
int	ft_putunsig_n(unsigned int n);
int	ptr_tohex(unsigned long nbr);
int	dec_tohex(unsigned int n, const char *chr);

#endif