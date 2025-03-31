/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:20:35 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/03/10 11:15:15 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert(va_list args, char c);

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		k;

	if (!str)
		return (0);
	i = 0;
	k = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (!str[i])
				return (1);
			k += convert(args, str[i]);
		}
		else
			k += ft_putchar_pf(str[i]);
		i++;
	}
	va_end(args);
	return (k);
}


static int	convert(va_list args, char c)
{
	int	k;

	k = 0;
	if (c == 'c')
		k = ft_putchar_pf(va_arg(args, int));
	else if (c == 's')
		k = ft_putstr_pf(va_arg(args, char *));
	else if (c == 'p')
		k = ft_putptr_pf(va_arg(args, unsigned long));
	else if (c == 'd' || c == 'i')
		k = ft_putnbr_pf(va_arg(args, int), 0);
	else if (c == 'u')
		k = ft_putuint_pf(va_arg(args, unsigned int), 0);
	else if (c == 'x')
		k = ft_puthex_pf(va_arg(args, unsigned int), 'x', 0);
	else if (c == 'X')
		k = ft_puthex_pf(va_arg(args, unsigned int), 'X', 0);
	else if (c == '%')
		k = ft_putchar_pf('%');
	return (k);
}
