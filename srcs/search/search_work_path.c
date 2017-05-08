/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_work_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:13:43 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 12:07:21 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

void		search_work_path(t_farm *f, t_path *p)
{
	t_room	*last;
	t_room	*neighb;
	size_t	i;

	last = *(t_room**)ft_ary_get(&p->p, p->p.item_count - 1);
	if (roomlist_has_room(&last->links, f->finish)) {
		search_path_room_queue(p, f->finish, &f->paths);
		return ;
	}
	i = 0;
	while (i < last->links.item_count)
	{
		neighb = *(t_room**)ft_ary_get(&last->links, i);
		if (!roomlist_has_room(&p->p, neighb))
			search_path_room_queue(p, neighb, &f->pathq);
		i++;
	}
}
