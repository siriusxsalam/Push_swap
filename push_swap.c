/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:29:38 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/29 15:54:01 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort2to5(t_node **sa, t_node **sb, int size)
{
	if (size == 2)
		swap(sa, 'a', 0);
	else if (size == 3)
		sort_three(sa);
	else if (size == 4)
		sort_four(sa, sb);
	else if (size == 5)
		sort_five(sa, sb);
}

void	ifsort(t_node **sa, t_node **sb, int size)
{
	t_node	*tmp;

	if (size == 1)
		exit(1);
	if (size > 5)
	{
		ft_swap(sa, sb, size);
		tmp = *sb;
		while ((*sb))
			index_maxbmax(sa, sb);
	}
	else
		ft_sort2to5(sa, sb, size);
}

int	main(int argc, char **argv)
{
	t_node	*sa;
	t_node	*sb;
	int		size;

	sa = NULL;
	sb = NULL;
	if (argc > 1)
	{
		if (first_check(argc, argv) == 1)
			return (1);
		sa = parss(argc, argv, sa);
		ft_duperror(&sa);
		ft_putindex(&sa);
		alreay_sort(&sa);
		size = ft_lstsize(sa);
		ifsort(&sa, &sb, size);
		alreay_sort(&sa);
	}
	return (0);
}
