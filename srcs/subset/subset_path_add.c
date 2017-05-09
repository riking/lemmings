/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subset_path_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 13:29:25 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 14:58:01 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

void		subset_add_path(t_pathset *s, t_path *p)
{
	size_t	i;
	t_room	*it;

	i = 0;
	while (i < p->p.item_count)
	{
		it = *(t_room**)ft_ary_get(&p->p, i);
		subset_room_set(s, it);
		i++;
	}
	ft_ary_append(&s->paths, &p);
}

bool		subset_conflict_path(t_pathset *s, t_path *p)
{
	size_t	i;
	t_room	*it;

	i = 0;
	while (i < p->p.item_count)
	{
		it = *(t_room**)ft_ary_get(&p->p, i);
		if (!it->is_start && !it->is_finish)
			if (subset_room_has(s, it))
				return (true);
		i++;
	}
	return (false);
}
