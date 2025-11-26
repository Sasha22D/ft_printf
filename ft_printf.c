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

	i = 0;
	va_start(args, s);
	while (str[i])
	{
		if (str[i] == '%')
		{
			handle_format(str[i + 1], args);
			i++;
		}
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}

#include <stdio.h>
int main(void)
{
	printf("returned: %d\n", ft_printf("\%c", '0'));
	printf("returned: %d\n", printf("\\%c", '0'));
}
