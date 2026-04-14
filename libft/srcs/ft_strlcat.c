/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:08:42 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/19 13:03:32 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	space_left;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	space_left = siz - dst_len - 1;
	if (dst_len >= siz)
		return (siz + src_len);
	else
	{
		while (src[i] && space_left--)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
