/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:33:14 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/29 15:48:56 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct node
{
	int			data;
	int			i;
	struct node	*next;
}	t_node;

void	swap_helper(t_node **s);
void	push_helper(t_node **src, t_node **dst);
void	retate_helper(t_node **s);
void	reverse_helper(t_node **s);
void	swap(t_node **s, char o, int check);
void	push(t_node **s, t_node **d, char o, int check);
void	retate(t_node **s, char o, int check);
void	reverse(t_node **s, char o, int check);
void	ss_rr_rrr(t_node **sa, t_node **sb, int n, int check);
void	ft_printerr(char *s, char **f);
void	ft_duperror(t_node **s);
void	ft_putindex(t_node **sa);
void	sort_three(t_node **s);
void	sort_four(t_node **sa, t_node **sb);
void	sort_five(t_node **sa, t_node **sb);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_strlcat(char *dst, const char *src, int dstsize);
int		ft_strlcpy(char *dst, const char *src, int dstsize);
int		ft_isdigit(int c);
int		ft_atoi(const char *str, char **t);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char const *s2);
t_node	*ft_lstnew(int cont, int indx);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstaddfront_back(t_node **lst, t_node *new, int flag);
int		ft_lstmax_beforemax(t_node **s, int flag);
int		ft_lstsize(t_node *lst);
void	ft_free_and_freelst(char **t, t_node **sa, int flag);
int		lentab(char	**t);
void	argcheck(char **t);
t_node	*parss(int argc, char **argv, t_node *sa);
void	print_action(int flag);
void	ft_swap(t_node **sa, t_node **sb, int t);
void	index_maxbmax(t_node **sa, t_node **sb);
int		find_pos(t_node **s, int index);
void	ft_lstdelone(t_node *lst);
void	ft_lstclear(t_node **lst);
int		alreay_checker_sort(t_node **sa);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		operatour_checker(char *s, t_node **sa, t_node **sb);
void	ft_pushsort(t_node **sa, t_node **sb, int p);
void	push_min2(t_node **sa, int flag);
void	ft_freecheck(t_node **s);
int		first_check(int argc, char **argv);

#endif
