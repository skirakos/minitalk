/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:23:17 by skirakos          #+#    #+#             */
/*   Updated: 2024/02/19 18:23:22 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*str_copy;

	len = ft_strlen(s1);
	str_copy = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	if (str_copy)
	{
		while (s1[i] != '\0')
		{
			str_copy[i] = s1[i];
			i++;
		}
		str_copy[i] = '\0';
		return (str_copy);
	}
	return (NULL);
}
