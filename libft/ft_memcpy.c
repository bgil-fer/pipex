/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:27:09 by bgil-fer          #+#    #+#             */
/*   Updated: 2024/10/12 12:03:58 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*org;
	unsigned char	*goal;

	i = 0;
	org = (unsigned char *)src;
	goal = (unsigned char *)dest;
	if (dest == 0 && src == 0)
		return (dest);
	while (n > 0)
	{
		goal[i] = org[i];
		n--;
		i++;
	}
	return (dest);
}
