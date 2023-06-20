/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:56:01 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/01 18:58:02 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	int		ss;
	char	*r;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	ss = ft_strlen(s1) + ft_strlen(s2);
	r = malloc(sizeof(char) * (ss + 1));
	if (!r)
		return (NULL);
	ft_strlcpy(r, s1, ft_strlen(s1) + 1);
	ft_strlcat(r, s2, ss + 1);
	free(s1);
	return (r);
}
