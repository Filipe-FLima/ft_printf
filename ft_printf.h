/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:07:27 by flima             #+#    #+#             */
/*   Updated: 2024/10/21 20:39:08 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "./Libft/libft.h"
#include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_putchar_n(int c);
int	ft_putstr_n(char *s);
int	ft_putnbr_n(int nb);
int	ft_putuns_n(unsigned int n);

#endif