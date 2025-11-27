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
	va_list	args_cpy;
	int		i;
	int		count;

	va_start(args, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			count = handle_format(s[i + 1], args, args_cpy, count);
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

void	ft_putunsigned(unsigned int n)
{
	unsigned char	c;

	if (n >= 10)
	{
		ft_putunsigned(n / 10);
		c = '0' + n % 10;
		write(1, &c, 1);
	}
	else
	{
		c = '0' + n;
		write(1, &c, 1);
	}
}

// #include <stdio.h>
// int main()
// {
// 	ft_printf("\nreturned: %d\n", ft_printf(" %X ", 42));
// 	printf("\nreturned: %d", printf(" %X ", 42));
// }
