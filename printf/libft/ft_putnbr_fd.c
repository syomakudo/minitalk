/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoma.k <syoma.k@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:25:00 by skudo             #+#    #+#             */
/*   Updated: 2022/11/02 15:13:43 by syoma.k          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit(int n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static int	n_abs(int n)
{
	if (n < 0)
		return (-1 * n);
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	str[12];
	size_t	count;

	ft_bzero(str, 12);
	count = digit(n);
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	while (n && (count--) >= 0)
	{
		str[count] = n_abs(n % 10) + '0';
		n /= 10;
	}
	ft_putstr_fd(str, fd);
}
