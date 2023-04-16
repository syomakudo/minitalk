/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skudo <skudo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:49:19 by skudo             #+#    #+#             */
/*   Updated: 2022/10/29 14:41:47 by skudo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
#include <stdio.h>
int main ()
{
	const char	*s;
	size_t		count;

	s = "hello";
	printf("%s\n", s);
	
	count = ft_strlen(s);
	printf("%lu\n", count);
	return (0);
}
*/