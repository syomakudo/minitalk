/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoma.k <syoma.k@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:30:33 by skudo             #+#    #+#             */
/*   Updated: 2022/11/05 15:16:51 by syoma.k          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	count;

	if (!dst && !src)
		return (NULL);
	if (src < dst)
	{
		count = len - 1;
		while (0 < len--)
		{
			*(unsigned char *)(dst + count) = *(unsigned char *)(src + count);
			count--;
		}
	}
	else
	{
		count = 0;
		while (0 < len--)
		{
			*(unsigned char *)(dst + count) = *(unsigned char *)(src++);
			count++;
		}
	}
	return (dst);
}

/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
    char buf1[] = "abc   ";
 	printf("%s\n", buf1);

    char *result1 = memmove(buf1,"xyz ",4);
	printf("main -> %s\n", result1);


    char buf2[] = "abc    ";

    char *result2 = ft_memmove(buf2,"xyz ",4);
	printf("ft   -> %s\n", result2);

    return (0);
} */