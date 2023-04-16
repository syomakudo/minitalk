/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skudo <skudo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:48:44 by skudo             #+#    #+#             */
/*   Updated: 2022/10/29 17:46:03 by skudo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int c)
{
	while ((*string) != '\0')
	{
		if (*((char *)(string++)) == (char)c)
			return ((char *)string - 1);
	}
	if (c == '\0')
		return ((char *)string);
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
#define SIZE 40
int main(void)
{
  char buffer1[SIZE] = "computer program";
  char * ptr;
  int    ch = 'p';
  ptr = ft_strchr( buffer1, 'l' + 256 );
  printf( "The first occurrence of %c in '%s' is '%s'\n",
            ch, buffer1, ptr );
  char *ptr2 = strchr( buffer1, 'l' + 256 );
  printf( "The first occurrence of %c in '%s' is '%s'\n",
            ch, buffer1, ptr2 );
}
*/