/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-02 07:57:40 by bgil-fer          #+#    #+#             */
/*   Updated: 2024/10/02 10:19:10 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	char	*t;

	ptr = malloc(sizeof(char) * ft_strlen((char *)s) + 1);
	t = ptr;
	if (ptr == 0)
		return (0);
	while (*s)
		*ptr++ = *s++;
	*ptr = '\0';
	return (t);
}
