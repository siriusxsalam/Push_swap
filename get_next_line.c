/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:30:26 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/03 22:23:17 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*grest(char *str)
{
	char	*r;
	int		i;
	int		j;

	i = 0;
	j = 0;
	i = ft_strlen_g(str, 1);
	if (!str[i])
		return (free(str), NULL);
	r = malloc((ft_strlen_g(str, 0) + 1 - i) * sizeof(char));
	if (!r)
		return (NULL);
	i++;
	while (str[i])
		r[j++] = str[i++];
	r[j] = '\0';
	free(str);
	return (r);
}

char	*gline(char *str)
{
	char	*l;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	i = ft_strlen_g(str, 1);
	if (str[i] == '\n')
		l = malloc(sizeof(char) * i + 2);
	else
		l = malloc(sizeof(char) * i + 1);
	if (!l)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		l[i] = str[i];
	if (str[i] == '\n')
	{
		l[i++] = '\n';
		l[i] = '\0';
	}
	else
		l[i] = '\0';
	return (l);
}

char	*ft_helper(int fd, t_handle *handle, char **str)
{
	while (handle->check != 0)
	{
		handle->check = read(fd, handle->buf, BUFFER_SIZE);
		if (handle->check == -1)
		{
			free(*str);
			*str = NULL;
			return (free(handle->buf), NULL);
		}
		handle->buf[handle->check] = '\0';
		*str = ft_strjoin_g(*str, handle->buf);
		if (!(*str))
			return (NULL);
		if (ft_strchr_g(*str, '\n'))
			break ;
	}
	free(handle->buf);
	handle->d = gline(*str);
	*str = grest(*str);
	return (handle->d);
}

char	*get_next_line(int fd)
{
	t_handle	handle;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	handle.buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!handle.buf)
		return (NULL);
	handle.check = 1;
	return (ft_helper(fd, &handle, &str));
}
