/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 12:34:19 by kyork             #+#    #+#             */
/*   Updated: 2016/10/21 21:01:34 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_PRIVATE_H
# define GET_NEXT_LINE_PRIVATE_H

# include <libft.h>
# include <sys/types.h>

typedef struct	s_gnl_fd {
	int		fd;
	ssize_t	nl_off;
	t_array	chars;
}				t_gnl_fd;

typedef struct	s_gnlstate {
	t_array fds;
}				t_gnlstate;

# ifndef BUFF_SIZE
#  define BUFF_SIZE 32
# endif

int				get_next_line(const int fd, char **line);

#endif
