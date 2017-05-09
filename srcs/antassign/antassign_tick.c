/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antassign_tick.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:57:37 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 16:01:25 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

static void	add_ant(t_farm *f, t_path *p, size_t finish_time)
{
	t_ant	ant;

	ant.path = p;
	ant.ant_id = f->ants.item_count;
	ant.offset = finish_time - p->p.item_count;
	ft_ary_append(&f->ants, &ant);
}

void		antassign_tick(t_farm *f, size_t finish_time)
{
	size_t	i;
	t_path	*p;

	i = 0;
	while (i < f->set->paths.item_count)
	{
		p = *(t_path**)ft_ary_get(&f->set->paths, i);
		if (p->p.item_count <= finish_time)
			add_ant(f, p, finish_time);
		i++;
	}
}
