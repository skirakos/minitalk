/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:30:07 by skirakos          #+#    #+#             */
/*   Updated: 2024/02/19 18:30:09 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s);
	ptr = (char *)s + len - 1;
	if (c == '\0')
		return (++ptr);
	while (len != 0)
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr--;
		len--;
	}
	return (NULL);
}
