/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skudo <skudo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:52:05 by skudo             #+#    #+#             */
/*   Updated: 2022/10/29 17:44:32 by skudo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;

	p = (const unsigned char *)s;
	while (n-- > 0)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
#define SIZE 40
int main(void)
{
  char buffer1[SIZE] = "abcd";
  char * ptr;
  int    ch = 'c';
  ptr = ft_memchr( buffer1, ch , 2);
  printf( "%s\n",ptr );
  char *ptr2 = memchr( buffer1, ch , 2);
  printf( "%s\n",ptr2 );
}
*/