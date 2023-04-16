/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoma.k <syoma.k@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:33:14 by skudo             #+#    #+#             */
/*   Updated: 2022/11/02 15:15:20 by syoma.k          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	count = 0;
	i = 0;
	src_len = ft_strlen(src);
	if (dst == NULL && src && dstsize == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	while (dst[count] != '\0')
		count++;
	while (src[i] != '\0' && count < dstsize - 1 && dstsize != 0)
		dst[count++] = src[i++];
	dst[count] = '\0';
	if (dstsize >= dst_len)
		return (dst_len + src_len);
	else
		return (src_len + dstsize);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char			str1[15];
	char			str2[];
	unsigned int	jk1;
	char			str11[15];
	char			str22[];
	unsigned int	dk1;
	char			str3[15];
	char			str4[];
	unsigned int	jk2;
	char			str33[15];
	char			str44[];
	unsigned int	dk2;
	char			str5[15];
	char			str6[];
	unsigned int	jk3;
	char			str55[15];
	char			str66[];
	unsigned int	dk3;
	char			str7[15];
	char			str8[];
	unsigned int	jk4;
	char			str77[15];
	char			str88[];
	unsigned int	dk4;

	str1[15] = "Hello";
	str2[] = "12300----";
	jk1 = ft_strlcat(str1, str2, 9);
	printf("%s : jk1 = %d\n", str1 , jk1);
	str11[15] = "Hello";
	str22[] = "12300----";
	dk1 = strlcat(str11, str22, 9);
	printf("%s : dk1 = %d\n\n", str11 , dk1);

	str3[15] = "Hello";
	str4[] = "12300----";
	jk2 = ft_strlcat(NULL, str4, 0);
	printf("%s : jk2 = %d\n", str3 , jk2);
	str33[15] = "Hello";
	str44[] = "12300----";
	dk2 = strlcat(NULL, str44, 0);
	printf("%s : dk2 = %d\n\n", str33 , dk2);
	str5[15] = "Hello";
	str6[] = "12300----";
	jk3 = ft_strlcat(str5, str6, 3);
	printf("%s : jk3 = %d\n", str5 , jk3);
	str55[15] = "Hello";
	str66[] = "12300----";
	dk3 = strlcat(str55, str66, 3);
	printf("%s : dk3 = %d\n\n", str55 , dk3);
	str7[15] = "Hello";
	str8[] = "12300----";
	jk4 = ft_strlcat(str7, str8, 15);
	printf("%s : jk4 = %d\n", str7 , jk4);
	str77[15] = "Hello";
	str88[] = "12300----";
	dk4 = strlcat(str77, str88, 15);
	printf("%s : dk4 = %d\n", str77 , dk4);
	return (0);
}
*/