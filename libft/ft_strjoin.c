/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:27:03 by skirakos          #+#    #+#             */
/*   Updated: 2024/02/19 18:27:05 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_new(size_t size)
{
	char	*str;

	str = (char *)malloc((size + 1) * sizeof(char));
	if (str != NULL)
	{
		ft_memset(str, '\0', (size + 1));
		return (str);
	}
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s1 && s2)
	{
		str = ft_new(ft_strlen(s1) + ft_strlen(s2));
		if (!str)
			return (NULL);
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
		while (s2[i - ft_strlen(s1)] != '\0')
		{
			str[i] = s2[i - ft_strlen(s1)];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
