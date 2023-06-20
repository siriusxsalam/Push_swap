/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:26:31 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/03 22:21:33 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_g(char *str, int flag)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (flag == 0)
	{
		while (str[i])
			i++;
	}
	else
	{
		while (str[i] && str[i] != '\n')
			i++;
	}
	return (i);
}

char	*ft_strjoin_g(char *str, char *buf)
{
	char	*d;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!buf || !str)
	{
		str = malloc(sizeof(char));
		if (!buf || !str)
			return (NULL);
		str[0] = '\0';
	}
	d = malloc((ft_strlen_g(str, 0) + ft_strlen_g(buf, 0)) + 1);
	if (!d)
		return (NULL);
	while (str[++i] != '\0')
		d[i] = str[i];
	while (buf[++j] != '\0')
		d[i + j] = buf[j];
	d[i + j] = '\0';
	free(str);
	return (d);
}

char	*ft_strchr_g(char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	if (c == '\0')
	{
		i = ft_strlen_g(str, 0);
		return ((char *)&str[i]);
	}
	i = -1;
	while (str[++i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
	}
	return (0);
}
