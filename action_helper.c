/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 01:28:32 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/19 15:50:55 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_helper(t_node **s)
{
	int		tmp;
	t_node	*lst;

	if (!(*s) || !(*s)->next)
		return ;
	lst = *s;
	tmp = lst->data;
	lst->data = lst->next->data;
	lst->next->data = tmp;
	tmp = lst->i;
	lst->i = lst->next->i;
	lst->next->i = tmp;
}

void	push_helper(t_node **src, t_node **dst)
{
	t_node	*lst;
	t_node	*s;

	if (!(*src))
		return ;
	s = *src;
	lst = ft_lstnew((*src)->data, (*src)->i);
	ft_lstaddfront_back(dst, lst, 0);
	*src = (*src)->next;
	free(s);
}

void	retate_helper(t_node **s)
{
	t_node	*lst;
	t_node	*tmp;

	if (!(*s) || !(*s)->next)
		return ;
	tmp = *s;
	lst = ft_lstnew((*s)->data, (*s)->i);
	ft_lstaddfront_back(s, lst, 1);
	*s = (*s)->next;
	free(tmp);
}

void	reverse_helper(t_node **s)
{
	t_node	*lst;
	t_node	*tmp;
	t_node	*last;

	if (!(*s))
		return ;
	last = *s;
	last = ft_lstlast(last);
	lst = ft_lstnew(last->data, last->i);
	ft_lstaddfront_back(s, lst, 0);
	tmp = *s;
	while ((*s)->next && (*s)->next->next)
		(*s) = (*s)->next;
	(*s)->next = NULL;
	(*s) = tmp;
	free(last);
}
