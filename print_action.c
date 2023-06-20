/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:49:50 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/04 17:32:29 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstrr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		i++;
	write(1, str, i);
}

void	print_action(int flag)
{
	if (flag == 1)
		ft_putstrr("sa\n");
	else if (flag == 2)
		ft_putstrr("sb\n");
	else if (flag == 3)
		ft_putstrr("ss\n");
	else if (flag == 4)
		ft_putstrr("ra\n");
	else if (flag == 5)
		ft_putstrr("rb\n");
	else if (flag == 6)
		ft_putstrr("rr\n");
	else if (flag == 7)
		ft_putstrr("rra\n");
	else if (flag == 8)
		ft_putstrr("rrb\n");
	else if (flag == 9)
		ft_putstrr("rrr\n");
	else if (flag == 10)
		ft_putstrr("pa\n");
	else if (flag == 11)
		ft_putstrr("pb\n");
}
