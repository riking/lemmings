/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_set_startfinish.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:53:28 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 14:10:21 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

static void		assign_sf(t_room **ptr, t_room *r)
{
	if (*ptr)
		PARSE_ERROR("Start/finish set twice");
	*ptr = r;
}

int				parse_set_startfinish(t_farm *f)
{
	t_room	*r;
	size_t	i;

	i = 0;
	while (i < f->layout.room_info.item_count)
	{
		r = *(t_room**)ft_ary_get(&f->layout.room_info, i);
		if (r->is_start)
			assign_sf(&f->start, r);
		else if (r->is_finish)
			assign_sf(&f->finish, r);
		i++;
	}
	if (!f->start || !f->finish)
		PARSE_ERROR("Start/finish not set");
	f->finish->end_dist = 0;
	flood_fill(f->finish);
	return (0);
}
