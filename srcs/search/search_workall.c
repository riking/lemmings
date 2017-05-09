/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_workall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:28:00 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 17:47:35 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include "../subset/type.h"
#include <ft_printf.h>
#include <limits.h>

static size_t	select_next(t_farm *f)
{
	size_t	best_idx;
	int		best_cost;
	size_t	i;
	t_path	*it;

	best_idx = 0;
	best_cost = INT_MAX;
	i = 0;
	while (i < f->pathq.item_count)
	{
		it = (t_path*)ft_ary_get(&f->pathq, i);
		if (search_path_cost(f, it) < best_cost)
		{
			best_idx = i;
			best_cost = search_path_cost(f, it);
		}
		i++;
	}
	return (best_idx);
}

static bool		is_good_enough(t_farm *f)
{
	ft_dprintf(2, "===HALT=== Stopping breadth-first search due to reaching "
			"32K steps and checking for a path set\n");
	subset_findn(f);
	if (f->set && f->set->paths.item_count == (size_t)max_path(f))
	{
		ft_dprintf(2, "===HALT=== Found a good path set, stopping search\n");
		return (true);
	}
	ft_dprintf(2, "===HALT=== Continuing\n");
	return (false);
}

void			search_workall(t_farm *f, size_t target_paths_count)
{
	size_t	steps;
	size_t	idx;
	t_path	p;

	steps = 0;
	while (f->pathq.item_count != 0 && f->paths.item_count < target_paths_count)
	{
		steps++;
		idx = select_next(f);
		p = *(t_path*)ft_ary_get(&f->pathq, idx);
		ft_dprintf(2, "[%5ld found] working path #%ld %p %6ld\n", f->paths.item_count,
				idx, p.p.ptr, steps);
		search_work_path(f, &p);
		ft_ary_destroy(&p.p);
		ft_ary_remove(&f->pathq, idx);
		if (steps == 32000)
		{
			steps = 0;
			if (is_good_enough(f))
				return ;
		}
	}
}
