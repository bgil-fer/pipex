/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 08:40:24 by bgil-fer          #+#    #+#             */
/*   Updated: 2024/10/18 13:14:54 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	if (ft_strlen(big) < ft_strlen(little))
		return (0);
	j = 0;
	while (big[j])
	{
		i = 0;
		if (big[j] == little[0])
		{
			while (big[i + j] == little[i] && (i + j) < len)
			{
				if (little[i + 1] == '\0')
					return ((char *)&big[j]);
				i++;
			}
		}
		j++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%s", ft_strnstr("abcdefgh", "abc", -1));
	return (0);
}
*/