/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skudo <skudo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:22:24 by skudo             #+#    #+#             */
/*   Updated: 2022/10/29 14:41:03 by skudo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (f == NULL || s == NULL)
		return ;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*
	void test(unsigned int i, char *str)
	{
		str[i] += 1;
	}
	#include <stdio.h>
int	main(void)
{
	void	(*f)(unsigned int, char *);
	char	str2[];

	f = test;
	str2[] = "abcde";
	ft_striteri(str2, f);
	printf("%s\n", str2);
	return (0);
}
*/