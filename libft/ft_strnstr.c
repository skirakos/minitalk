/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:29:54 by skirakos          #+#    #+#             */
/*   Updated: 2024/02/19 18:29:56 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	char		*str1;
	char		*str2;

	str1 = (char *)haystack;
	str2 = (char *)needle;
	if (!haystack && len == 0)
		return (NULL);
	if (*str2 == '\0')
		return (str1);
	i = ft_strlen(str2);
	while (*str1 && len >= i)
	{
		if (*str1 == *str2 && ft_strncmp(str1, str2, i) == 0)
			return (str1);
		len--;
		str1++;
	}
	return (NULL);
}
