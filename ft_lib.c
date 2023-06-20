/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:35:28 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/04 16:22:18 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*sorc;
	size_t	i;

	i = 0;
	if (dst == src || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	dest = (char *)dst;
	sorc = (char *)src;
	while (i < n)
	{
		dest[i] = sorc[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	size_t	l;
	char	*r;

	l = ft_strlen(s1) + 1;
	r = malloc(sizeof(char) * l);
	if (!r)
		return (NULL);
	r = ft_memcpy(r, s1, l);
	return (r);
}

int	ft_strlcat(char *dst, const char *src, int dstsize)
{
	t_lib	l_handle;

	l_handle.i = 0;
	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	l_handle.d = ft_strlen(dst);
	while (src[l_handle.i] != '\0' && l_handle.d + 1 < dstsize)
	{
		dst[l_handle.d] = src[l_handle.i];
		l_handle.i++;
		l_handle.d++;
	}
	dst[l_handle.d] = '\0';
	l_handle.s = ft_strlen(dst) + ft_strlen(&src[l_handle.i]);
	return (l_handle.s);
}

int	ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int	i;
	int	n;

	i = 0;
	n = ft_strlen(src);
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (n);
}
