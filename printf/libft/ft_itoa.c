/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoma.k <syoma.k@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:21:20 by syoma.k           #+#    #+#             */
/*   Updated: 2022/11/02 15:12:06 by syoma.k          ###   ########.fr       */
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

char	*ft_itoa(int n)
{
	char	*str;
	size_t	count;

	count = digit(n);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!(str))
		return (NULL);
	str[count] = '\0';
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	while (n && (count--) >= 0)
	{
		str[count] = n_abs(n % 10) + '0';
		n /= 10;
	}
	return (str);
}

/*
#include <libc.h>

__attribute__((destructor))
static void	destructor(void) {
    system("leaks -q a.out");
}
#include <stdio.h>
int	main(void)
{
	int		n;
	char	*s;
	char	*result1;
	char	*result2;
	char	*result3;
	char	*result4;

	n = -123456;
	s = "hello";
	result1 = ft_itoa(-2147483648);
	printf("%s\n", result1);
	result2 = ft_itoa(0);
	printf("%s\n", result2);
	result3 = ft_itoa(2147483647);
	printf("%s\n", result3);
	result4 = ft_itoa(42);
	printf("%s\n", result4);
	free(result1);
	free(result2);
	free(result3);
	free(result4);
	return (0);
}
*/