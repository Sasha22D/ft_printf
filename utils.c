/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:37:17 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/25 14:53:29 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./libft/libft.h"
#include "ft_printf.h"

int	ft_itohex(unsigned int n, char *base, int count)
{
	if (n >= 16)
		ft_itohex(n / 16, base, count++);
	write(1, &base[n % 16], 1);
	return (count);
}

int	ft_print_hex(uintptr_t n, char *base, int count)
{
	if (n >= 16)
		ft_print_hex(n / 16, base, count++);
	write(1, &base[n % 16], 1);
	return (count);
}

void	ft_print_memory(void *ptr, char *base, int count)
{
	uintptr_t	addr;

	addr = (uintptr_t)ptr;
	ft_putstr_fd("0x", 1);
	ft_print_hex(addr, base, count);
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

int	ft_putstr(char *s, int count)
{
	while (*s)
	{
		write(1, &s, 1);
		count++;
		s++;
	}
	return (count);
}

int	handle_format(char c, va_list args, int count)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1), count++);
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *), 1));
	else if (c == 'p')
		ft_print_memory(va_arg(args, void *), "0123456789abcdef", count);
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int), count));
	else if (c == 'x')
		return (ft_itohex(va_arg(args, unsigned int), "0123456789abcdef", count));
	else if (c == 'X')
		return (ft_itohex(va_arg(args, unsigned int), "0123456789ABCDEF", count));
	else if (c == '%')
		return (ft_putchar_fd(va_arg(args, int), 1), count++);
	return (count);
}
