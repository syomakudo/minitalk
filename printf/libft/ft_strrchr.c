/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoma.k <syoma.k@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:14:33 by skudo             #+#    #+#             */
/*   Updated: 2022/11/05 23:33:19 by syoma.k          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long long	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

#define SIZE 40

int	main(void)
{
  char buffer1[SIZE] = "computer program";
  char * ptr;
  int ch = 'p';

  ptr = strrchr( NULL, ch );
  printf( "%c\n%s\n%s\n\n",
            ch, buffer1, ptr );

}
*/