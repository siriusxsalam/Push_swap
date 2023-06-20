/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:45:55 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/26 12:56:34 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **s)
{
	t_node	*tmp;

	tmp = *s;
	if (tmp->i < tmp->next->i && tmp->next->i > tmp->next->next->i
		&& tmp->next->next->i > tmp->i)
	{
		reverse(s, 'a', 0);
		swap(s, 'a', 0);
	}
	else if (tmp->i > tmp->next->i && tmp->next->i > tmp->next->next->i
		&& tmp->next->next->i < tmp->i)
	{
		swap(s, 'a', 0);
		reverse(s, 'a', 0);
	}
	else if (tmp->i < tmp->next->i && tmp->next->i > tmp->next->next->i
		&& tmp->next->next->i < tmp->i)
		reverse(s, 'a', 0);
	else if (tmp->i > tmp->next->i && tmp->next->i < tmp->next->next->i
		&& tmp->next->next->i < tmp->i)
		retate(s, 'a', 0);
	else if (tmp->i > tmp->next->i && tmp->next->i < tmp->next->next->i
		&& tmp->next->next->i > tmp->i)
		swap(s, 'a', 0);
}

void	push_min1(t_node **sa, int flag)
{
	if (flag == 2)
		swap(sa, 'a', 0);
	else if (flag == 3)
	{
		retate(sa, 'a', 0);
		retate(sa, 'a', 0);
	}
	else if (flag == 4)
	{
		reverse(sa, 'a', 0);
		reverse(sa, 'a', 0);
	}
	else if (flag == 5)
		reverse(sa, 'a', 0);
}

void	push_min2(t_node **sa, int flag)
{
	if (flag == 2)
		swap(sa, 'a', 0);
	else if (flag == 3)
	{
		reverse(sa, 'a', 0);
		reverse(sa, 'a', 0);
	}
	else if (flag == 4)
		reverse(sa, 'a', 0);
}

void	sort_four(t_node **sa, t_node **sb)
{
	t_node	*tmp;
	int		p;

	p = 0;
	tmp = *sa;
	while (tmp)
	{
		p++;
		if (tmp->i == 0)
			break ;
		tmp = tmp->next;
	}
	ft_pushsort(sa, sb, p);
}

void	sort_five(t_node **sa, t_node **sb)
{
	int		p;
	t_node	*tmp;

	p = 0;
	tmp = *sa;
	while (tmp)
	{
		p++;
		if (tmp->i == 0)
			break ;
		tmp = tmp->next;
	}
	push_min1(sa, p);
	push(sa, sb, 'b', 0);
	p = 0;
	tmp = *sa;
	while (tmp)
	{
		p++;
		if (tmp->i == 1)
			break ;
		tmp = tmp->next;
	}
	ft_pushsort(sa, sb, p);
	push(sb, sa, 'a', 0);
}
