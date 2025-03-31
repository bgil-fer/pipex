/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42student.c     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:52:04 by bgil-fer          #+#    #+#             */
/*   Updated: 2024/10/07 09:46:43 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	count(char const *s, char c)
{
	size_t	num;
	size_t	i;

	i = 0;
	num = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			num++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (num);
}

static char	**free_mem(char **result)
{
	size_t	k;

	k = 0;
	while (result[k])
		free(result[k++]);
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	result = ft_calloc(count(s, c) + SPACE_FOR_NULL, sizeof(char *));
	if (!result)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		result[k] = ft_calloc(i - j + SPACE_FOR_NULL, sizeof(char));
		if (!result[k])
			return (free_mem(result));
		ft_memcpy(result[k++], &s[j], i - j);
	}
	return (result);
}
/*
int	main(void)
{
	size_t	i;
	char	**ptr;

	i = 0;
	ptr = ft_split("", 0);
	//printf("%s\n", ptr[0]);

	while (ptr[i])
	{
		printf("|%s|\n", ptr[i]);
		i++;
	}
	printf("|%s|\n", ptr[i]);
	return (0);
}*/
