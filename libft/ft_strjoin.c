/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42student.c     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-02 10:07:19 by bgil-fer          #+#    #+#             */
/*   Updated: 2024/10/02 12:46:33 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (ptr == 0)
		return (NULL);
	while (s1[i] != 0)
	{
		ptr[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		ptr[i] = *s2;
		s2++;
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
