/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:17:34 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/19 12:32:54 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*o;
	size_t			i;

	i = 0;
	o = (unsigned char *)dest;
	p = (unsigned char *)src;
	if (o == p || n == 0)
		return (dest);
	if (o < p)
	{
		while (i < n)
		{
			*o++ = *p++;
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			o[n] = p[n];
	}
	return (dest);
}
