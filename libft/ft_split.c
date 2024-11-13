/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:11:40 by skirakos          #+#    #+#             */
/*   Updated: 2024/02/19 17:11:45 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_memelem(char **res, int j, int k)
{
	res[k] = (char *)malloc((j + 1) * sizeof(char));
	if (!res[k])
	{
		while (k >= 0)
			free(res[k--]);
	}
	res[k][j] = '\0';
	return (res);
}

int	ft_countwords(char const *s, char c)
{
	int		i;
	int		count;
	int		len;

	len = ft_strlen(s);
	i = 0;
	count = 0;
	while (i < len)
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && i < len)
				i++;
		}
		i++;
	}
	return (count);
}

char	**ft_memallocate(char const *s, char **res, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < (int)ft_strlen(s))
	{
		if (s[i] != c)
		{
			while (s[i] != c && i < (int)ft_strlen(s))
			{
				j++;
				i++;
			}
			ft_memelem(res, j, k);
			j = 0;
			k++;
		}
		i++;
	}
	return (res);
}

char	**ft_res(char **res, char const *s, char c, int count)
{
	int		j;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[k] != '\0' && i < count)
	{
		if (s[k] != c)
		{
			j = 0;
			while (s[k] != c && s[k] != '\0')
			{
				res[i][j] = s[k];
				k++;
				j++;
			}
			i++;
		}
		else
			k++;
	}
	res[count] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**res;

	if (!s)
		return (NULL);
	count = ft_countwords(s, c);
	res = (char **)malloc((count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res = ft_memallocate(s, res, c);
	return (ft_res(res, s, c, count));
}
