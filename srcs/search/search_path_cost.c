/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path_cost.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 12:00:31 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 18:23:21 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

static int	conflict_penalty(t_farm *f, t_path *p)
{
	int		penalty;
	size_t	i;
	t_path	*itp;

	penalty = 0;
	i = 0;
	while (i < f->paths.item_count)
	{
		itp = (t_path*)ft_ary_get(&f->paths, i);
		if (paths_conflict(p, itp))
			penalty += 2;
		i++;
	}
	return (penalty);
}

int			search_path_cost(t_farm *f, t_path *p)
{
	int		penalty;
	size_t	i;
	t_room	*it;
	t_room	*prev;

	if (p->cost != 0)
		return (p->cost);
	penalty = p->p.item_count;
	i = 1;
	while (i < p->p.item_count)
	{
		prev = *(t_room**)ft_ary_get(&p->p, i - 1);
		it = *(t_room**)ft_ary_get(&p->p, i);
		if (it->end_dist >= prev->end_dist)
			penalty += 2;
		i++;
	}
	penalty += conflict_penalty(f, p);
	p->cost = penalty;
	return (penalty);
}
