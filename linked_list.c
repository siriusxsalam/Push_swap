/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 05:51:59 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/04 16:25:51 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int cont, int indx)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->data = cont;
	n->i = indx;
	n->next = NULL;
	return (n);
}

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstaddfront_back(t_node **lst, t_node *new, int flag)
{
	t_node	*l;

	if (flag == 0)
	{
		(void)l;
		if (!*lst)
			*lst = new;
		else if (new)
		{
			new->next = *lst;
			*lst = new;
		}
	}
	else
	{
		if (!*lst)
			*lst = new;
		else if (new)
		{
			l = ft_lstlast(*lst);
			l->next = new;
		}
	}
}

int	ft_lstmax_beforemax(t_node **s, int flag)
{
	int		m;
	int		bm;
	t_node	*tmp;

	tmp = (*s);
	m = 0;
	bm = 0;
	while (tmp)
	{
		if (m < tmp->i)
			m = tmp->i;
		tmp = tmp->next;
	}
	tmp = (*s);
	while (tmp)
	{
		if (bm < tmp->i && tmp->i != m)
			bm = tmp->i;
		tmp = tmp->next;
	}
	if (flag == 0)
		return (m);
	else
		return (bm);
}

int	ft_lstsize(t_node *lst)
{
	int		s;
	t_node	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	s = 0;
	while (tmp)
	{
		tmp = tmp->next;
		s++;
	}
	return (s);
}
