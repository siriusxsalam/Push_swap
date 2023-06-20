/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:54:18 by hasalam           #+#    #+#             */
/*   Updated: 2023/04/20 17:28:47 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	countword(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static	char	*putword(char *word, char const *s, int i, int len)
{
	int	j;

	j = 0;
	while (len > 0)
	{
		word[j] = s[i - len];
		j++;
		len--;
	}
	word[j] = '\0';
	return (word);
}

static	int	ft_freesplit(char **s, int i)
{
	int	f;

	f = 0;
	if (!s[i])
	{
		while (i--)
			free(s[i]);
		free(s);
		f = 1;
	}
	return (f);
}

static	char	**splitword(char const *s1, char c, char **s2, int nw)
{
	int	i;
	int	w;
	int	len;

	i = 0;
	w = 0;
	len = 0;
	while (w < nw)
	{
		while (s1[i] && s1[i] == c)
			i++;
		while (s1[i] && s1[i] != c)
		{
			i++;
			len++;
		}
		s2[w] = malloc(sizeof(char) * (len + 1));
		if (ft_freesplit(s2, w) == 1)
			return (NULL);
		putword(s2[w], s1, i, len);
		len = 0;
		w++;
	}
	s2[w] = NULL;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char	**s2;
	int		nw;

	if (!s)
		return (NULL);
	nw = countword(s, c);
	s2 = malloc(sizeof(char *) * (nw + 1));
	if (!s2)
		return (NULL);
	s2 = splitword(s, c, s2, nw);
	return (s2);
}
