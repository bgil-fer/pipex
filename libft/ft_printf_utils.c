/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:42:31 by bgil-fer          #+#    #+#             */
/*   Updated: 2024/11/19 10:42:31 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_pf(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_pf(char *s)
{
	int	i;

	i = 0;
	if (!s)
		i += ft_putstr_pf("(null)");
	else
	{
		while (s[i])
		{
			ft_putchar_pf(s[i]);
			i++;
		}
	}
	return (i);
}

int	ft_putnbr_pf(int n, int a)
{
	static int	l;

	if (a == 0)
		l = 0;
	if (n == -2147483648)
	{
		l += ft_putstr_pf("-2147483648");
		return (l);
	}
	else if (n > 9 && n <= 2147483647)
	{
		ft_putnbr_pf(n / 10, 1);
		ft_putnbr_pf(n % 10, 1);
	}
	else if (n < 0)
	{
		l += ft_putchar_pf('-');
		ft_putnbr_pf(-n, 1);
	}
	else
		l += ft_putchar_pf(n + 48);
	return (l);
}

int	ft_puthex_pf(unsigned long n, char x, int a)
{
	char		*hex;
	static int	o;

	if (a == 0)
		o = 0;
	if (x == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_puthex_pf(n / 16, x, 1);
	}
	ft_putchar_pf(hex[n % 16]);
	o++;
	return (o);
}

int	ft_putptr_pf(unsigned long ptr)
{
	int	i;

	i = 0;
	if (!ptr)
	{
		i += ft_putstr_pf("(nil)");
		return (i);
	}
	i += ft_putstr_pf("0x");
	i += ft_puthex_pf(ptr, 'x', 0);
	return (i);
}
