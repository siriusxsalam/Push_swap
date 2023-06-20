/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:32:21 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/22 17:44:49 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	alreay_checker_sort(t_node **sa)
{
	int		i;
	t_node	*tmp;

	if (!(*sa))
		return (0);
	tmp = *sa;
	i = 1;
	while (tmp && tmp->next != NULL)
	{
		if (tmp->i < tmp->next->i)
			i++;
		tmp = tmp->next;
	}
	if (ft_lstsize(*sa) == i)
		return (1);
	else
		return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n--)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			return ((unsigned char)*s1 - (unsigned char)*s2);
	}
	return (0);
}

int	operatour_checker(char *s, t_node **sa, t_node **sb)
{
	if (!ft_strncmp(s, "sa\n", 3))
		return (swap(sa, 'a', 1), 1);
	else if (!ft_strncmp(s, "sb\n", 3))
		return (swap(sb, 'b', 1), 1);
	else if (!ft_strncmp(s, "ss\n", 3))
		return (ss_rr_rrr(sa, sb, 1, 1), 1);
	else if (!ft_strncmp(s, "ra\n", 3))
		return (retate(sa, 'a', 1), 1);
	else if (!ft_strncmp(s, "rb\n", 3))
		return (retate(sb, 'b', 1), 1);
	else if (!ft_strncmp(s, "rr\n", 3))
		return (ss_rr_rrr(sa, sb, 2, 1), 1);
	else if (!ft_strncmp(s, "rra\n", 4))
		return (reverse(sa, 'a', 1), 1);
	else if (!ft_strncmp(s, "rrb\n", 4))
		return (reverse(sb, 'b', 1), 1);
	else if (!ft_strncmp(s, "rrr\n", 4))
		return (ss_rr_rrr(sa, sb, 3, 1), 1);
	else if (!ft_strncmp(s, "pa\n", 3))
		return (push(sb, sa, 'b', 1), 1);
	else if (!ft_strncmp(s, "pb\n", 3))
		return (push(sa, sb, 'b', 1), 1);
	else
		return (ft_printf("Error\n"), 0);
}

void	main_helper(t_node **sa, t_node **sb)
{
	char	*s;

	s = get_next_line(0);
	while (s)
	{
		if (operatour_checker(s, sa, sb) == 1)
		{
			free(s);
			s = get_next_line(0);
		}
		else
		{
			free(s);
			exit(1);
		}
	}
	if (alreay_checker_sort(sa) == 1 && !(*sb))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	t_node	*sa;
	t_node	*sb;

	sa = NULL;
	sb = NULL;
	if (ac > 1)
	{
		sa = parss(ac, av, sa);
		ft_duperror(&sa);
		ft_putindex(&sa);
		main_helper(&sa, &sb);
	}
	ft_freecheck(&sa);
	ft_freecheck(&sb);
	return (0);
}
