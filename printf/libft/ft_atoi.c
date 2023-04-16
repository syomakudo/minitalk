/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoma.k <syoma.k@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:12:37 by skudo             #+#    #+#             */
/*   Updated: 2022/11/08 07:01:23 by syoma.k          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	check_over(char c, long number, int sign)
{
	long	ov_div;
	long	ov_mod;

	if (sign == -1)
		return (0);
	ov_div = LONG_MAX / 10;
	ov_mod = LONG_MAX % 10;
	if (number > ov_div || ((number == ov_div) && (((int)c - '0') > ov_mod)))
		return (1);
	return (0);
}

static int	check_under(char c, long number, int sign)
{
	long	ov_div;
	long	ov_mod;

	if (sign == 1)
		return (0);
	ov_div = (LONG_MIN) / 10;
	ov_mod = (LONG_MIN) % 10 * (-1);
	number = number * -1;
	if (number < ov_div || ((number == ov_div) && (((int)c - '0') > ov_mod)))
		return (1);
	return (0);
}

static int	atooi(char *str, int sign)
{
	long	number;

	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		number += (*str) - '0';
		if (!(*(str + 1) >= '0' && *(str + 1) <= '9'))
			break ;
		if (check_over(*(str + 1), number, sign))
			return ((int)LONG_MAX);
		if (check_under(*(str + 1), number, sign))
			return ((int)LONG_MIN);
		number *= 10;
		str++;
	}
	return (number);
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		num;
	char	*str1;

	str1 = (char *)str;
	sign = 1;
	while ((*str1 >= '\t' && *str1 <= '\r') || *str1 == ' ')
		str1++;
	if (*str1 == '-' || *str1 == '+')
	{
		if (*str1 == '-')
			sign *= -1;
		str1++;
	}
	if (!(*str1 >= '0' && *str1 <= '9'))
		return (0);
	num = atooi(str1, sign);
	num *= sign;
	return (num);
}

/*
#include <stdio.h>
int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	char st1[] = "9223372036854775808";
	int num = ft_atoi(st1);
	// int num = ft_atoi(argv[1]);
	printf("%d\n", num);
	char st2[] = "9223372036854775808";
	int num2 = atoi(st2);
	printf("%d\n", num2);
	return (0);
}
*/