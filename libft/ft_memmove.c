/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:03:03 by bgil-fer          #+#    #+#             */
/*   Updated: 2024/10/23 09:12:44 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*org;
	unsigned char	*goal;

	if (!dest && !src)
		return (0);
	org = (unsigned char *)src;
	goal = (unsigned char *)dest;
	if (goal > org)
	{
		while (n-- > 0)
			goal[n] = org[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			goal[i] = org[i];
			i++;
		}
	}
	return (dest);
}
