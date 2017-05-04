/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_workall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:28:00 by kyork             #+#    #+#             */
/*   Updated: 2017/05/04 16:12:55 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <ft_printf.h>
#include <limits.h>

static size_t	select_next(t_farm *f)
{
	size_t	best_idx;
	size_t	best_len;
	size_t	i;
	t_path	*it;

	best_idx = 0;
	best_len = INT_MAX;
	i = 0;
	while (i < f->pathq.item_count)
	{
		it = (t_path*)ft_ary_get(&f->pathq, i);
		if (it->item_count < best_len)
		{
			best_idx = i;
			best_len = it->item_count;
		}
		i++;
	}
	return (best_idx);
}

void			search_workall(t_farm *f)
{
	size_t	idx;
	t_path	p;

	while (f->pathq.item_count != 0 && f->paths.item_count < 20)
	{
		idx = select_next(f);
		p = *(t_path*)ft_ary_get(&f->pathq, idx);
		ft_printf("working path #%ld\n", idx);
		search_work_path(f, &p);
		ft_ary_destroy(&p);
		ft_ary_remove(&f->pathq, idx);
	}
	ft_ary_destroy(&f->pathq);
	f->pathq = FT_ARY_NULL;
}
