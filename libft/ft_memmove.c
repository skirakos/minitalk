/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:19:39 by skirakos          #+#    #+#             */
/*   Updated: 2024/02/19 18:19:47 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*cpy_dst;
	const char		*cpy_src;
	unsigned int	i;

	cpy_dst = (char *)dst;
	cpy_src = (char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		while (i < len)
		{
			cpy_dst[i] = cpy_src[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i--)
			cpy_dst[i] = cpy_src[i];
	}
	return (cpy_dst);
}
