/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoma.k <syoma.k@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 06:59:32 by syoma.k           #+#    #+#             */
/*   Updated: 2022/11/09 17:46:35 by syoma.k          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putchar(int c)
{
	unsigned char	result;

	result = (unsigned char)c;
	return (write(1, &result, 1));
}

ssize_t	ft_putstr(const char *s)
{
	size_t	len;
	ssize_t	count;

	if (s == NULL)
		return (ft_putstr("(null)"));
	len = ft_strlen(s);
	if (len > INT32_MAX)
	{
		count = write(1, s, INT32_MAX);
		if (count == -1)
			exit(1);
		s += INT32_MAX;
		return (count + ft_putstr(s));
	}
	return (write(1, s, len));
}

ssize_t	ft_func(const char c, va_list arg)
{
	ssize_t	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar((char)va_arg(arg, int));
	else if (c == 's')
		count += ft_putstr((char *)va_arg(arg, char *));
	else if (c == 'p')
		count += ft_chagehex((uintptr_t)va_arg(arg, uintptr_t), c);
	else if (c == 'd' || c == 'i')
		count += ft_putnbr((int)va_arg(arg, int));
	else if (c == 'u')
		count += ft_putnbr_u((unsigned int)va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		count += ft_chagehex((unsigned long)va_arg(arg, unsigned int), c);
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	arg;
	ssize_t	count;
	ssize_t	check;

	count = 0;
	va_start(arg, fmt);
	if (!fmt)
		return (-1);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			check = ft_func(*fmt, arg);
		}
		else
			check = ft_putchar(*fmt);
		fmt++;
		count += check;
		if (check == -1 || count > __INT_MAX__)
			return (-1);
	}
	va_end(arg);
	return (count);
}

// int main ()
// {
// 	char s[6] = "World";
// int	a = printf("%c  %s  %p  %d  %i  %u  %x  %X  %%\n",
// 		'h', "ello", &s[0], 10, 10, 50, 255, 255);
// int	b = ft_printf("%c  %s  %p  %d  %i  %u  %x  %X  %%\n",
// 		'h', "ello", &s[0], 10, 10, 50, 255, 255);
// 	printf("a = %d\nb = %d", a, b);
// 	// printf("\n%d",ft_printf("hello", 'y'));
// 	// char change[6] = "hello";
// 	// ft_chagehex(&change[0], 'p');
// 	// write(1, "\n", 1);
// 	// // ft_chagehex(&change[0], 'x');
// 	// ft_chagehex((unsigned long)0x7FFFFFFF, 'x');
// 	// write(1, "\n", 1);
// 	// // ft_chagehex(&change[0], 'X');
// 	// ft_chagehex((unsigned long)0x7FFFFFFF, 'X');
// 	// printf("\n%x",&change[0]);
// 	return (0);
// }