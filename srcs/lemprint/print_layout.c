/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_layout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 16:25:55 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 17:30:13 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <ft_printf.h>

void		print_layout(t_farm_layout *layout, int fd)
{
	size_t	i;
	t_room	*it;

	print_comments(&layout->antcount_comments, fd);
	ft_dprintf(fd, "%d\n", layout->ant_count);
	i = 0;
	while (i < layout->room_info.item_count)
	{
		it = *(t_room**)ft_ary_get(&layout->room_info, i++);
		print_room(layout, it, fd);
	}
	i = 0;
	while (i < layout->room_info.item_count)
	{
		it = *(t_room**)ft_ary_get(&layout->room_info, i++);
		print_room_links(layout, it, fd);
	}
	print_comments(&layout->trail_comments, fd);
}
