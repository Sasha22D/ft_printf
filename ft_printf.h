/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:41:33 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/25 12:42:09 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <stdarg.h>
# include <stdint.h>

int	ft_putunsigned(unsigned int n, int count);
int	ft_itohex(unsigned int n, char *base, int count);
int	ft_print_hex(uintptr_t n, char *base, int count);
int	ft_print_memory(void *ptr, char *base, int count);
int	ft_printf(const char *s, ...);
int	ft_putstr(char *s, int count);
int	handle_format(char c, va_list args, int count);

#endif
