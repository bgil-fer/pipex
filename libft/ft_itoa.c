/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:47:19 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/03/17 19:50:07 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digit(long int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			count;
	char		*ptr;
	long int	num;

	num = n;
	count = ft_count_digit(n);
	ptr = ft_calloc(count + 1, sizeof(char));
	if (ptr == NULL)
		return (0);
	if (num < 0)
	{
		ptr[0] = '-';
		num = -num;
	}
	ptr[count] = 0;
	count--;
	while (count != 0)
	{
		ptr[count] = (num % 10) + 48;
		num = num / 10;
		count--;
	}
	if (ptr[0] != '-')
		ptr[count] = (num % 10) + 48;
	return (ptr);
}
