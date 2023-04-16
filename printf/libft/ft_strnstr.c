/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skudo <skudo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:10:29 by skudo             #+#    #+#             */
/*   Updated: 2022/10/29 15:12:43 by skudo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	search(char *sorce, char *check, int check_size, size_t times)
{
	int	check_box;

	while (check_size > 0)
	{
		check_box = *sorce - *check;
		if (!check_box)
		{
			sorce++;
			check++;
		}
		check_size--;
		if (times-- <= 0)
			return (1);
	}
	return (check_box);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		len_haystack;
	int		len_find;
	char	*copy;

	if (haystack == NULL && len == 0)
		return (NULL);
	copy = (char *)haystack;
	len_haystack = ft_strlen(haystack);
	len_find = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)copy);
	if (len_haystack < len_find)
		return (NULL);
	while (len_haystack >= len_find && len > 0)
	{
		if (!search((char *)haystack, (char *)needle, len_find, len))
			return ((char *)haystack);
		haystack++;
		len_haystack--;
		len--;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void){
	char *str = "libft-test-tokyo";
	int	len = strlen(str);
		printf("ori : %s \t\t\n", strnstr(NULL, "fake", 0));
		printf("test : %s\n",ft_strnstr(NULL, "1", 0));
	return (0);
}
*/