/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:28:47 by skirakos          #+#    #+#             */
/*   Updated: 2024/02/19 18:28:48 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	int		i;

	if (s && f)
	{
		new_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (!new_str)
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			new_str[i] = (*f)(i, s[i]);
			i++;
		}
		new_str[i] = '\0';
		return (new_str);
	}
	return (NULL);
}
