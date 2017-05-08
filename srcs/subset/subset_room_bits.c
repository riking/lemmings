/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subset_room_bits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 13:20:19 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 13:22:37 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

bool		subset_room_has(t_pathset *s, t_room *r)
{
	size_t	by;

	by = r->id / 8;
	if (s->used_rooms[by] & (1 << (r->id % 8)))
		return (true);
	return (false);
}

void		subset_room_set(t_pathset *s, t_room *r)
{
	size_t	by;

	by = r->id / 8;
	s->used_rooms[by] |= (1 << (r->id % 8));
}

void		subset_room_clear(t_pathset *s, t_room *r)
{
	size_t	by;

	by = r->id / 8;
	s->used_rooms[by] &= ~(1 << (r->id % 8));
}
