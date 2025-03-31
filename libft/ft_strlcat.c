/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:57:25 by bgil-fer          #+#    #+#             */
/*   Updated: 2024/10/12 13:27:25 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	size_t	i;

	i = 0;
	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	if (size == 0)
		return (len_s);
	if (size < len_d)
		len_s = len_s + size;
	else
		len_s = len_s + len_d;
	while ((len_d + i) < (size - 1) && src[i])
	{
		dst[len_d + i] = src[i];
		i++;
	}
	dst[len_d + i] = 0;
	return (len_s);
}
