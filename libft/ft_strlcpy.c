/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:17:14 by bgil-fer          #+#    #+#             */
/*   Updated: 2024/10/12 12:42:36 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srcsize;

	srcsize = ft_strlen(src);
	if (size > 0)
	{
		i = 0;
		while (i < srcsize && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (srcsize);
}
/*
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	origin[] = "0123456789";
	char	destination[55] = "abcde";
	unsigned int	size;
	int	n;

	size = 9;
	printf("Origen: %s. Destino: %s\n", origin, destination);
	n = strlcpy(destination, origin, size);
	printf("Origen: %s. Destino: %s\n", origin, destination);
	printf("El tamaño de la cadena de origen es: %i", n);
	return (0);
}*/