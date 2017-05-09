/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_room_links.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 16:28:41 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 16:49:23 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <ft_printf.h>

void		print_room_links(t_farm_layout *layout, t_room *r, int fd)
{
	size_t	i;
	t_array	*com;
	t_room	*other;

	(void)layout;
	i = 0;
	while (i < r->links.item_count)
	{
		com = (t_array*)ft_ary_get(&r->link_comments, i);
		other = *(t_room**)ft_ary_get(&r->links, i);
		if (com->ptr != LINK_OUTPUT_SENTINEL)
		{
			print_comments(com, fd);
			ft_dprintf(fd, "%s-%s\n", r->name, other->name);
		}
		i++;
	}
}
