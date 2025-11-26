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

void	ft_putunsigned(unsigned int n);
void	ft_itohex(unsigned int n, char *base);
void	ft_print_hex(uintptr_t n, char *base);
void	ft_print_memory(void *ptr, char *base);
int     ft_printf(const char *s, ...);

#endif
