/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoma.k <syoma.k@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:26:09 by skudo             #+#    #+#             */
/*   Updated: 2022/11/05 15:15:48 by syoma.k          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int num, size_t len)
{
	unsigned char	*ptr;

	ptr = dst;
	while (len-- > 0)
		*ptr++ = (unsigned char)num;
	return (dst);
}
