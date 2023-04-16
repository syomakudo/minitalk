/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoma.k <syoma.k@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:39:32 by syoma.k           #+#    #+#             */
/*   Updated: 2022/11/05 17:00:02 by syoma.k          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	j;
	char	*result;

	if (!s1 | !s2)
		return (NULL);
	result = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	len = 0;
	j = 0;
	while (len < ft_strlen(s1) + ft_strlen(s2))
	{
		if (len < ft_strlen(s1))
			result[len] = s1[len];
		else
		{
			result[len] = s2[j];
			j++;
		}
		len++;
	}
	result[len] = '\0';
	return (result);
}
