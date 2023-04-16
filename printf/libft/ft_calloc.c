/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skudo <skudo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:19:48 by skudo             #+#    #+#             */
/*   Updated: 2022/10/29 14:36:27 by skudo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	check;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	check = count * size;
	if (check / count != size)
		return (NULL);
	p = (void *)malloc(count * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
    char *ch;

    ch = (char*)ft_calloc((size_t)SIZE_MAX / 10 + (size_t)1, 10);
    // puts("文字列を入力してください。");
    // gets(ch);
    printf("入力した文字は→%s\n",ch);
    free(ch);
    return (0);
}
*/