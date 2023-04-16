/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoma.k <syoma.k@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:39:19 by skudo             #+#    #+#             */
/*   Updated: 2022/11/05 15:14:07 by syoma.k          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	count;

	if (!dst && !src)
		return (NULL);
	count = 0;
	while (0 < n--)
	{
		*(unsigned char *)(dst + count) = *(unsigned char *)src++;
		count++;
	}
	return (dst);
}
