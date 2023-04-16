/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skudo <skudo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:51:17 by skudo             #+#    #+#             */
/*   Updated: 2022/10/29 14:41:41 by skudo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		countdown;
	char		*dst_copy;
	const char	*src_copy;

	dst_copy = dst;
	src_copy = src;
	countdown = size;
	if (countdown != 0)
	{
		while (--countdown != 0)
		{
			*(dst_copy++) = *src_copy;
			if (*(src_copy++) == '\0')
				break ;
		}
	}
	if (countdown == 0)
	{
		if (size != 0)
			*dst_copy = '\0';
		while (*(src_copy++))
			;
	}
	return (src_copy - src - 1);
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
	jk1 = ft_strlcpy(str1, str2, 9);
	printf("%s : jk1 = %d\n", str1 , jk1);
	str11[15] = "Hello";
	str22[] = "12300----";
	dk1 = strlcpy(str11, str22, 9);
	printf("%s : dk1 = %d\n\n", str11 , dk1);
	
	str3[15] = "Hello";
	str4[] = "12300----";
	jk2 = ft_strlcpy(str3, str4, 0);
	printf("%s : jk2 = %d\n", str3 , jk2);
	str33[15] = "Hello";
	str44[] = "12300----";
	dk2 = strlcpy(str33, str44, 0);
	printf("%s : dk2 = %d\n\n", str33 , dk2);
	str5[15] = "Hello";
	str6[] = "12300----";
	jk3 = ft_strlcpy(str5, str6, 3);
	printf("%s : jk3 = %d\n", str5 , jk3);
	str55[15] = "Hello";
	str66[] = "12300----";
	dk3 = strlcpy(str55, str66, 3);
	printf("%s : dk3 = %d\n\n", str55 , dk3);
	str7[15] = "";
	str8[] = "12300----";
	jk4 = ft_strlcpy(str7, str8, 15);
	printf("%s : jk4 = %d\n", str7 , jk4);
	str77[15] = "";
	str88[] = "12300----";
	dk4 = strlcpy(str77, str88, 15);
	printf("%s : dk4 = %d\n", str77 , dk4);
char	c[256] = "42tokyo";
  printf("%zu\n",  ft_strlcpy(NULL  , "aiueo", 0));  // 5);
//   ft_strlcpy(NULL  , "aiueo", 2);  // segmentation fault
//   ft_strlcpy(c     , NULL   , 0);  // segmentation fault
//   ft_strlcpy(c     , NULL   , 2);  // segmentation fault
//   ft_strlcpy(NULL  , NULL   , 0);  // segmentation fault
//   ft_strlcpy(NULL  , NULL   , 2);  // segmentation fault
	return (0);
}
*/