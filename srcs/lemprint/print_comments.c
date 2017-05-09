/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_comments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 16:31:10 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 16:32:47 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <ft_printf.h>

void	print_comments(t_array *comments, int fd)
{
	size_t	i;
	char	*s;

	i = 0;
	while (i < comments->item_count)
	{
		s = *(char**)ft_ary_get(comments, i);
		ft_dprintf(fd, "%s\n", s);
		i++;
	}
}
