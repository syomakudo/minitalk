/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoma.k <syoma.k@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:19:18 by skudo             #+#    #+#             */
/*   Updated: 2022/11/05 16:44:57 by syoma.k          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	size_t	count;
	char	*p;

	count = 0;
	while (s1[count])
		count++;
	p = (char *)malloc(sizeof(char) * (count + 1));
	if (p == NULL)
		return ((char *) NULL);
	ft_strcpy(p, s1);
	return (p);
}

/*
#include <stdio.h>
int	main(void)
{
	char		*p;
	const char	str[];

	str[] = "abcde";
	p = ft_strdup(str);
	printf("%s\n", str);
	printf("%s\n", p);
	free(p);
	return (0);
}
*/
