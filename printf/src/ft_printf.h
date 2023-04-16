/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoma.k <syoma.k@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:03:38 by skudo             #+#    #+#             */
/*   Updated: 2022/11/09 16:53:02 by syoma.k          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);

char	*ft_itoa(int n);

ssize_t	ft_putchar(int c);

ssize_t	ft_putchar(int c);

ssize_t	ft_putstr(const char *s);

ssize_t	ft_chagehex(unsigned long p, char format);

ssize_t	ft_putnbr(int n);

char	*ft_utoa(unsigned int n);

ssize_t	ft_putnbr_u(unsigned int n);

ssize_t	ft_func(const char c, va_list arg);

int		ft_printf(const char *fmt, ...);

#endif
