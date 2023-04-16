/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_func1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoma.k <syoma.k@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:53:51 by syoma.k           #+#    #+#             */
/*   Updated: 2022/11/09 16:57:01 by syoma.k          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_chagehex(unsigned long p, char format)
{
	ssize_t	count;
	char	*text;

	text = NULL;
	count = 0;
	if (format == 'x' || format == 'p')
		text = "0123456789abcdef";
	else if (format == 'X')
		text = "0123456789ABCDEF";
	if (p >= 16)
		count += ft_chagehex(p / 16, format);
	else if (p < 16 && format == 'p')
		count += write(1, "0x", 2);
	count += write(1, &text[p % 16], 1);
	if (count == -1)
		exit(1);
	return (count);
}

ssize_t	ft_putnbr(int n)
{
	ssize_t	count;
	char	*str;

	str = ft_itoa(n);
	count = ft_putstr(str);
	free(str);
	str = NULL;
	return (count);
}

char	*ft_utoa(unsigned int n)
{
	char			*str;
	size_t			count;
	unsigned int	digit;

	digit = n;
	count = 0;
	if (digit == 0)
		count = 1;
	while (digit)
	{
		digit /= 10;
		count++;
	}
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!(str))
		return (NULL);
	str[count] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n && (count--) >= 0)
	{
		str[count] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

ssize_t	ft_putnbr_u(unsigned int n)
{
	ssize_t	count;
	char	*str;

	str = ft_utoa(n);
	count = ft_putstr(str);
	free(str);
	str = NULL;
	return (count);
}
