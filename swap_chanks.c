/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_chanks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:07:18 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/19 16:09:52 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_help(t_node **sa, t_node **sb, int chank, int tmp)
{
	while ((*sa)->i >= chank)
		retate(sa, 'a', 0);
	if ((*sa)->i <= chank - (tmp / 2))
		push(sa, sb, 'b', 0);
	else if ((*sa)->i > chank - (tmp / 2))
	{
		push(sa, sb, 'b', 0);
		if ((*sa) && (*sa)->i >= chank)
			ss_rr_rrr(sa, sb, 2, 0);
		else
			retate(sb, 'b', 0);
	}
}

void	ft_swap(t_node **sa, t_node **sb, int t)
{
	int	chank;
	int	tmp;

	if (t <= 20)
		chank = (t / 2);
	else if (t <= 200)
		chank = (t / 6);
	else if (t <= 500)
		chank = (t / 10);
	else
		chank = t / 14;
	tmp = chank;
	while ((*sa))
	{
		swap_help(sa, sb, chank, tmp);
		if (ft_lstsize(*sb) == chank)
			chank = chank + tmp;
	}
}

void	push_to_a(t_node **sa, t_node **sb, int index)
{
	int	i;

	i = find_pos(sb, index);
	if (i > ft_lstsize(*sb) / 2)
	{
		while (i++ < ft_lstsize(*sb))
			reverse(sb, 'b', 0);
	}
	else if (i <= ft_lstsize(*sb) / 2)
	{
		while (i-- > 0)
			retate(sb, 'b', 0);
	}
	if (*sb)
		push(sb, sa, 'a', 0);
}

void	index_maxbmax(t_node **sa, t_node **sb)
{
	t_list	handle;

	handle.m = ft_lstmax_beforemax(sb, 0);
	handle.bm = ft_lstmax_beforemax(sb, 1);
	handle.i_m = find_pos(sb, handle.m);
	handle.i_bm = find_pos(sb, handle.bm);
	if (handle.i_bm > ft_lstsize(*sb) / 2)
		handle.i_bm = ft_lstsize(*sb) - handle.i_bm;
	if (handle.i_m > ft_lstsize(*sb) / 2)
		handle.i_m = ft_lstsize(*sb) - handle.i_m;
	if (handle.i_m > handle.i_bm)
	{
		push_to_a(sa, sb, handle.bm);
		push_to_a(sa, sb, handle.m);
		swap(sa, 'a', 0);
	}
	else
	{
		push_to_a(sa, sb, handle.m);
		push_to_a(sa, sb, handle.bm);
	}
}

int	find_pos(t_node **s, int index)
{
	t_node	*tmp;
	int		pos;

	tmp = *s;
	pos = 0;
	while (tmp)
	{
		if (tmp->i == index)
			break ;
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}
