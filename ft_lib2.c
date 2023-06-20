/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:22:53 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/22 17:10:30 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	if_atoi_condition(const char *str, int n, int i, char **t)
{
	long	r;

	r = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		r = (r * 10) + (str[i] - 48);
		i++;
	}
	if (str[i])
		ft_printerr("Error", t);
	if ((n * r) > 2147483647 || (n * r) < -2147483648)
		ft_printerr("Error", t);
	return (n * r);
}

int	ft_atoi(const char *str, char **t)
{
	int		i;
	long	n;

	i = 0;
	n = 1;
	while (str[i] == '\t' || str[i] == '\r' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\n' || str[i] == ' ')
		i++;
	if ((str[i] == '+' || str[i] == '-') && \
		(str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		if (str[i] == '-')
			n = n * -1;
		i++;
	}
	return (if_atoi_condition(str, n, i, t));
}

void	ft_freecheck(t_node **s)
{
	t_node	*tmp;

	while ((*s))
	{
		tmp = (*s);
		(*s) = (*s)->next;
		free(tmp);
	}
}
