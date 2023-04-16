/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skudo <skudo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:36:07 by syoma.k           #+#    #+#             */
/*   Updated: 2022/10/29 17:55:03 by skudo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*copy(char const *s, unsigned int start, size_t len, char *result)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			result[j] = s[i];
			j++;
		}
		i++;
	}
	result[j] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	else if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	copy(s, start, len, result);
	return (result);
}

/* 
#include <stdio.h>
#include <string.h>
int main ()
{
	char	*str;
	char	*s;

	// char const *s = "libft-test-tokyo";
	// unsigned int start = 20;
	// size_t len = 100;
	// char *result=ft_substr(s, start, len);
	// printf("%s\n", result);
	// free(result);
	str = strdup("1");
	s = ft_substr(str, 42, 42000000);
	return (0);
}
 */