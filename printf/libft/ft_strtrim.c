/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoma.k <syoma.k@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:22:36 by syoma.k           #+#    #+#             */
/*   Updated: 2022/11/05 17:09:58 by syoma.k          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_front(char const *s1, char const *set)
{
	size_t	count;
	size_t	j;
	size_t	i;

	i = 0;
	count = 0;
	while (s1[i])
	{
		j = 0;
		while (1)
		{
			if (!set[j])
				return (count);
			if (s1[i] == set[j++])
			{
				count++;
				break ;
			}
		}
		i++;
	}
	return (count);
}

static int	count_back(char const *s1, char const *set, int i)
{
	int	count;
	int	j;

	count = 0;
	while (--i >= 0)
	{
		j = 0;
		while (1)
		{
			if (!set[j])
				return (count);
			if (s1[i] == set[j++])
			{
				count++;
				break ;
			}
		}
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	start = count_front(s1, set);
	end = count_back(s1, set, ft_strlen(s1));
	if ((int)ft_strlen(s1) - start - end > 0)
		result = (char *)malloc(sizeof(char)
				* (ft_strlen(s1) - start - end + 1));
	else
		result = (char *)malloc(sizeof(char) * 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while ((int)ft_strlen(s1) - start - end > 0)
	{
		result[i] = s1[start];
		start++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

// char	*aaaatest()
// {
// 	char	*test;

// 	test = malloc(100);
// 	return (test);
// }
// #include <stdio.h>
// #include <string.h>
// int main ()
// {
// 	char const *s1 = "123";
// 	char const *set = "";
// 	char *test = malloc(sizeof(char) * 1000);
// 	char *a = aaaatest();

// 	char *result = ft_strtrim(s1, set);
// 	printf("%s\n", result);
// 	system("leaks a.out");
// 	free(result);
// 	return (0);
// }
