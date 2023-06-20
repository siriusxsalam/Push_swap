/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:05:56 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/29 15:55:21 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printerr(char *s, char **f)
{
	ft_free_and_freelst(f, NULL, 1);
	ft_printf("%s\n", s);
	exit (1);
}

void	ft_duperror(t_node **s)
{
	t_node	*i_list;
	t_node	*j_list;
	int		i;
	int		j;

	i_list = *s;
	i = 0;
	while (i_list)
	{
		j_list = *s;
		j = 0;
		while (j_list)
		{
			if (j_list->data == i_list->data && i != j)
			{
				ft_free_and_freelst(NULL, s, 0);
				ft_printf("Error\n");
				exit (1);
			}
			j_list = j_list->next;
			j++;
		}
		i_list = i_list->next;
		i++;
	}
}

int	first_check(int argc, char **argv)
{
	int	i;
	int	j;
	int	c;

	i = 1;
	while (i < argc)
	{
		j = 0;
		c = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
				c = 1;
			j++;
		}
		if (!c)
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}
