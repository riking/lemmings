/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 16:23:11 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 16:34:17 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <ft_printf.h>

void		print_room(t_farm_layout *layout, t_room *r, int fd)
{
	(void)layout;
	print_comments(&r->comments, fd);
	ft_dprintf(fd, "%s %d %d\n", r->name, r->coord_x, r->coord_y);
}
