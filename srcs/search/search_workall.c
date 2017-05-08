/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_workall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:28:00 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 14:13:05 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
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

void			search_workall(t_farm *f, size_t target_paths_count)
{
	size_t	idx;
	t_path	p;

	if (target_paths_count < 1)
		target_paths_count = 20;
	while (f->pathq.item_count != 0 && f->paths.item_count < target_paths_count)
	{
		idx = select_next(f);
		p = *(t_path*)ft_ary_get(&f->pathq, idx);
		ft_printf("[%5ld found] working path #%ld %p\n", f->paths.item_count, idx,
				p.p.ptr);
		search_work_path(f, &p);
		ft_ary_destroy(&p.p);
		ft_ary_remove(&f->pathq, idx);
	}
}
