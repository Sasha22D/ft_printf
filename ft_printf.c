/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:02:35 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/25 14:54:21 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./libft/libft.h"
#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count = handle_format(s[i + 1], args, count);
			i++;
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

int	ft_putunsigned(unsigned int n, int count)
{
	unsigned char	c;

	if (n >= 10)
	{
		ft_putunsigned(n / 10, count++);
		c = '0' + n % 10;
		write(1, &c, 1);
	}
	else
	{
		c = '0' + n;
		write(1, &c, 1);
		count++;
	}
	return (count);
}

// #include <stdio.h>
// int main()
// {
// 	ft_printf("\nreturned: %d\n", ft_printf(" %X ", 42));
// 	printf("\nreturned: %d", printf(" %X ", 42));
// }
