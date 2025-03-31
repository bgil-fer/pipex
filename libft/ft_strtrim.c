/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42student.c     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-02 10:48:13 by bgil-fer          #+#    #+#             */
/*   Updated: 2024/10/04 19:35:33 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*ptr;
	size_t		i;
	size_t		j;

	i = 0;
	while (ft_strchr(set, s1[i]) != NULL && s1[i])
		i++;
	j = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[j]) != NULL && j > 0)
		j--;
	if (i > j)
		ft_strdup("");
	ptr = ft_substr(s1, i, (j - i + 1));
	if (!set)
		return (NULL);
	return (ptr);
}
