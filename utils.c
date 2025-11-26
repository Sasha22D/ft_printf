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

void	ft_itohex(unsigned int n, char *base)
{
	if (n >= 16)
		ft_itohex(n / 16, base);
	write(1, &base[n % 16], 1);
}

void	ft_print_hex(uintptr_t n, char *base)
{
	if (n >= 16)
		ft_print_hex(n / 16, base);
	write(1, &base[n % 16], 1);
}

void	ft_print_memory(void *ptr, char *base)
{
	uintptr_t	addr;

	addr = (uintptr_t)ptr;
	ft_putstr_fd("0x", 1);
	ft_print_hex(addr, base);
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

void	handle_format(char c, va_list args)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		ft_print_memory(va_arg(args, void *), "0123456789abcdef");
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		ft_putunsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		ft_itohex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		ft_itohex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		ft_putchar_fd(va_arg(args, char), 1);
}
