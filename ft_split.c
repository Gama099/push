/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salah <salah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:36:50 by salah             #+#    #+#             */
/*   Updated: 2024/07/07 23:39:32 by salah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	count;

	count = 0;
	if (dstsize == 0 || src == NULL)
		return (0);
	while (--dstsize && *src)
	{
		*dest++ = *src++;
		count++;
	}
	*dest = '\0';
	return (count);
}

size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		x;

	count = 0;
	while (*s)
	{
		x = 0;
		while (*s && *s != c)
		{
			if (!x)
				count++;
			x = 1;
			s++;
		}
		while (*s && *s == c)
			s++;
	}
	return (count);
}

void	safe_alloc(char **arr, size_t count, int i)
{
	arr[i] = malloc(count + 1);
	if (!arr[i])
	{
		while (i)
		{
			free(arr[i]);
			i--;
		}
	}
}

void	fill(char const *s, char c, char **arr)
{
	size_t	count;
	int		i;
	char	*tmp;

	count = 0;
	i = 0;
	while (*s)
	{
		while (*s && *s != c)
		{
			if (!count)
				tmp = (char *)s;
			count++;
			s++;
		}
		while (*s && *s == c)
		{
			if (count)
			{
				safe_alloc(arr, count, i);
				ft_strlcpy(arr[i], tmp, count + 1);
				i++;
			}
			count = 0;
			s++;
		}
		if (!*s && count)
		{
			safe_alloc(arr, count, i);
			ft_strlcpy(arr[i], tmp, count + 1);
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	count;

	count = count_words(s, c);
	arr = malloc((count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr[count] = NULL;
	fill(s, c, arr);
	return (arr);
}
