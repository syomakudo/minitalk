/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoma.k <syoma.k@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:07:40 by syoma.k           #+#    #+#             */
/*   Updated: 2022/11/07 14:48:16 by syoma.k          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	checker(char src, char c)
{
	if (src == c || src == '\0')
		return (1);
	return (0);
}

static int	count_master(char const *str, char c)
{
	size_t	count;
	size_t	j;

	count = 0;
	j = 0;
	while (str[j])
	{
		if (!(checker(str[j], c)))
			if (checker(str[j + 1], c))
				count++;
		j++;
	}
	return (count);
}

static char	**make_sp(char **split, char const *str, char c, size_t count)
{
	size_t		i;
	long long	j;
	size_t		sub_count;

	j = 0;
	i = 0;
	while (j < (long long)count)
	{
		sub_count = 0;
		while (checker(str[i], c))
			i++;
		while (!(checker(str[i++], c)))
			sub_count++;
		split[j] = (char *)malloc(sizeof(char) * (sub_count + 1));
		if (split[j] == NULL)
		{
			while (j--)
				free(split[j + 1]);
			free(split);
			return (NULL);
		}
		j++;
	}
	return (split);
}

static char	**push(char **split, char const *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	count;

	j = 0;
	i = 0;
	k = 0;
	count = count_master(str, c);
	while (j < count)
	{
		k = 0;
		while (checker(str[i], c))
			i++;
		while (!(checker(str[i], c)))
			split[j][k++] = str[i++];
		split[j][k++] = '\0';
		j++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *str, char c)
{
	size_t	count;
	char	**split;

	if (str == NULL)
		return (NULL);
	count = count_master(str, c);
	split = (char **)malloc(sizeof(char const *) * (count + 1));
	if (split == NULL)
		return (NULL);
	split = make_sp(split, str, c, count);
	split = push(split, str, c);
	return (split);
}

/* #include <unistd.h>
size_t	main(void)
{
	char	**result;
	char	str[];
	char	c;

	str[] = "01234536789";
	c = '3';
	result = push(ft_split(str, c),str, c);
	printf("%s\n",*result);
	result += 1;
	printf("%s\n",*result);
	result += 1;
	printf("%s\n",*result);
	return (0);
}
 */