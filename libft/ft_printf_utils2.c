/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:18:29 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/03/10 11:01:01 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putuint_pf(unsigned int n, int a)
{
	static int	m;

	if (a == 0)
		m = 0;
	if (n > 9 && n <= 4294967295)
	{
		ft_putuint_pf(n / 10, 1);
		ft_putuint_pf(n % 10, 1);
	}
	else
	{
		m++;
		ft_putchar_pf(n + 48);
	}
	return (m);
}
