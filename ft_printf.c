/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:02:35 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/27 13:58:49 by sadaniel         ###   ########.fr       */
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

	if (!s)
		return (-1);
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
	return (va_end(args), count);
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
// #include <limits.h>
// #include "ft_printf.h"

// int main(void)
// {
//     int r1, r2;

//     char          c       = 'A';
//     char         *s       = "Hello";
//     char         *empty   = "";
//     char         *null_s  = NULL;
//     int           d       = 42;
//     int           neg     = -42;
//     int           min     = INT_MIN;
//     unsigned int  u0      = 0;
//     unsigned int  u42     = 42;
//     unsigned int  ux      = 0xabcdef;
//     void         *p       = &d;
//     void         *null_p  = NULL;

//     /* --------- CHAR / STRING --------- */
//     printf("=== CHAR / STRING ===\n");
//     r1 = printf("printf   : [%c] [%s] [%s] [%s]\n", c, s, empty, null_s);
//     r2 = ft_printf("ft_printf: [%c] [%s] [%s] [%s]\n", c, s, empty, null_s);
//     printf("ret printf   = %d\n", r1);
//     printf("ret ft_printf= %d\n\n", r2);

//     /* --------- POINTERS --------- */
//     printf("=== POINTERS ===\n");
//     r1 = printf("printf   : [%p] [%p]\n", p, null_p);
//     r2 = ft_printf("ft_printf: [%p] [%p]\n", p, null_p);
//     printf("ret printf   = %d\n", r1);
//     printf("ret ft_printf= %d\n\n", r2);

//     /* --------- SIGNED INT --------- */
//     printf("=== SIGNED INT ===\n");
//     r1 = printf("printf   : [%d] [%i] [%d]\n", d, neg, min);
//     r2 = ft_printf("ft_printf: [%d] [%i] [%d]\n", d, neg, min);
//     printf("ret printf   = %d\n", r1);
//     printf("ret ft_printf= %d\n\n", r2);

//     /* --------- UNSIGNED / HEX --------- */
//     printf("=== UNSIGNED / HEX ===\n");
//     r1 = printf("printf   : [%u] [%u] [%x] [%X] [%x]\n",
//                 u0, u42, ux, ux, u0);
//     r2 = ft_printf("ft_printf: [%u] [%u] [%x] [%X] [%x]\n",
//                    u0, u42, ux, ux, u0);
//     printf("ret printf   = %d\n", r1);
//     printf("ret ft_printf= %d\n\n", r2);

//     /* --------- POURCENT + MIX --------- */
//     printf("=== PERCENT + MIX ===\n");
//     r1 = printf("printf   : %% %% %%\n");
//     r2 = ft_printf("ft_printf: %% %% %%\n");
//     printf("ret printf   = %d\n", r1);
//     printf("ret ft_printf= %d\n\n", r2);

//     r1 = printf("printf   : c=%c s=%s p=%p d=%d u=%u x=%x %%\n",
//                 c, s, p, d, u42, ux);
//     r2 = ft_printf("ft_printf: c=%c s=%s p=%p d=%d u=%u x=%x %%\n",
//                    c, s, p, d, u42, ux);
//     printf("ret printf   = %d\n", r1);
//     printf("ret ft_printf= %d\n\n", r2);

//     return 0;
// }
