/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:31:00 by hasalam           #+#    #+#             */
/*   Updated: 2023/05/03 22:21:45 by hasalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct n_handle
{
	char		*d;
	char		*buf;
	int			check;
}	t_handle;

char	*grest(char *str);
char	*gline(char *str);
char	*get_next_line(int fd);
int		ft_strlen_g(char *str, int flag);
char	*ft_strjoin_g(char *str, char *buf);
char	*ft_strchr_g(char *str, int c);

#endif
