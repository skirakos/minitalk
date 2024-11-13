/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:19:10 by skirakos          #+#    #+#             */
/*   Updated: 2024/02/19 18:19:17 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*cpy_dst;
	char	*cpy_src;

	cpy_dst = (char *)dst;
	cpy_src = (char *)src;
	if (!dst && !src)
		return (NULL);
	while (n != 0)
	{
		cpy_dst[n - 1] = cpy_src[n - 1];
		n--;
	}
	return (dst);
}
