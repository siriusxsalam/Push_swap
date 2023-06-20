/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:52:57 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/08 18:25:32 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **s, char o, int check)
{
	swap_helper(s);
	if (o == 'a' && check == 0)
		print_action(1);
	else if (o == 'b' && check == 0)
		print_action(2);
}

void	push(t_node **s, t_node **d, char o, int check)
{
	push_helper(s, d);
	if (o == 'a' && check == 0)
		print_action(10);
	else if (o == 'b' && check == 0)
		print_action(11);
}

void	retate(t_node **s, char o, int check)
{
	retate_helper(s);
	if (o == 'a' && check == 0)
		print_action(4);
	else if (o == 'b' && check == 0)
		print_action(5);
}

void	reverse(t_node **s, char o, int check)
{
	reverse_helper(s);
	if (o == 'a' && check == 0)
		print_action(7);
	else if (o == 'b' && check == 0)
		print_action(8);
}

void	ss_rr_rrr(t_node **sa, t_node **sb, int n, int check)
{
	if (n == 1)
	{
		swap_helper(sa);
		swap_helper(sb);
		if (check == 0)
			print_action(3);
	}
	else if (n == 2)
	{
		retate_helper(sa);
		retate_helper(sb);
		if (check == 0)
			print_action(6);
	}
	else if (n == 3)
	{
		reverse_helper(sa);
		reverse_helper(sb);
		if (check == 0)
			print_action(9);
	}
}
