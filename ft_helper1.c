/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 02:05:19 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/04 16:18:28 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alreay_sort(t_node **sa)
{
	int		i;
	t_node	*tmp;

	if (!(*sa))
		return ;
	tmp = *sa;
	i = 1;
	while (tmp && tmp->next != NULL)
	{
		if (tmp->i < tmp->next->i)
			i++;
		tmp = tmp->next;
	}
	if (ft_lstsize(*sa) == i)
		exit(0);
}

void	ft_putindex(t_node **sa)
{
	int		i;
	t_node	*lst1;
	t_node	*lst2;
	t_node	*tmp;

	lst1 = *sa;
	tmp = lst1;
	if (!(*sa))
		return ;
	while (lst1)
	{
		i = 0;
		lst2 = tmp;
		while (lst2)
		{
			if (lst1->data > lst2->data)
				i++;
			lst2 = lst2->next;
		}
		lst1->i = i;
		lst1 = lst1->next;
	}
}

void	ft_lstdelone(t_node *lst)
{
	if (lst)
		return ;
	free(lst);
}

void	ft_lstclear(t_node **lst)
{
	t_node	*l;

	if (*lst)
	{
		while (*lst)
		{
			l = (*lst)->next;
			ft_lstdelone(*lst);
			*lst = l;
		}
		lst = NULL;
	}
}

void	ft_pushsort(t_node **sa, t_node **sb, int p)
{
	push_min2(sa, p);
	push(sa, sb, 'b', 0);
	sort_three(sa);
	push(sb, sa, 'a', 0);
}
