/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:33:03 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/19 12:51:26 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_and_freelst(char **t, t_node **sa, int flag)
{
	t_node	*tfree;
	int		i;

	i = -1;
	if (flag == 0)
	{
		while ((*sa))
		{
			tfree = *sa;
			(*sa) = (*sa)->next;
			free (tfree);
		}
	}
	else
	{
		while (t[++i])
			free (t[i]);
		free(t);
	}
}

int	lentab(char	**t)
{
	int	i;

	i = 0;
	while (t[i])
		i++;
	return (i);
}

void	argcheck(char **t)
{
	int	j;
	int	k;
	int	lt;

	k = 0;
	lt = lentab(t);
	while (k < lt)
	{
		j = 0;
		if (t[k][j] == '-' || t[k][j] == '+')
			j++;
		while (t[k][j] != '\0')
		{
			if (t[k][j] < '0' || t[k][j] > '9')
			{
				ft_free_and_freelst(t, NULL, 1);
				ft_printf("Error\n");
				exit (1);
			}
			else
				j++;
		}
		k++;
	}
}

void	parss_check(char **argv, t_parss handle)
{
	if (argv[handle.i][0] == '\0')
	{
		free(handle.s);
		ft_printf("Error\n");
		exit (1);
	}
}

t_node	*parss(int argc, char **argv, t_node *sa)
{
	t_parss	handle;

	handle.i = 0;
	handle.s = ft_strdup("");
	while (++handle.i < argc)
	{
		parss_check(argv, handle);
		handle.s = ft_strjoin(handle.s, argv[handle.i]);
		handle.s = ft_strjoin(handle.s, " ");
	}
	handle.i = 0;
	handle.t = ft_split(handle.s, ' ');
	free (handle.s);
	if (!handle.t[0])
		ft_printerr("Error", handle.t);
	argcheck(handle.t);
	sa = ft_lstnew(ft_atoi(handle.t[handle.i++], handle.t), 0);
	while (handle.t[handle.i])
		ft_lstaddfront_back(&sa, ft_lstnew(ft_atoi(handle.t[handle.i++], \
			handle.t), 0), 1);
	return (ft_free_and_freelst(handle.t, NULL, 1), sa);
}
