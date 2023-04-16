/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skudo <skudo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:20:50 by skudo             #+#    #+#             */
/*   Updated: 2022/10/29 17:45:06 by skudo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int main ()
{
	int		len;
	char	*str;
	char	*cmp;

		len = 30;
	str = calloc(30, sizeof(char));
	cmp = calloc(30, sizeof(char));
	memcpy(str, "libft-test-tokyo", 16);
	memcpy(cmp, "libft-test-tokyo", 16);
	memcpy(str + 20, "acdfg", 5);
	memcpy(cmp + 20, "acdfg", 5);
	for (int i = 21; i <= len; i++)
	{
		cmp = strndup(str, i);
		printf("%d : %d \t\t",i, ft_memcmp(str, cmp, i));
		printf("%d : %d \t\t\n",i, memcmp(str, cmp, i));
		free(cmp);
	}
	free (str);
	free (cmp);
	return (0);
}
*/
