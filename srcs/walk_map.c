/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 12:14:16 by kyork             #+#    #+#             */
/*   Updated: 2017/01/12 15:05:00 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "farm.h"
#include <libft.h>

bool		path_contains(t_array path, t_room *check)
{
	t_room	**ary;
	int		idx;

	ary = path.ptr;
	idx = 0;
	while (idx < path.item_count)
	{
		if (ary[idx++] == check)
			return (true);
	}
	return (false);
}

bool		path_subsumed(t_farm *f, t_array path)
{
	int		idx[2];
	bool	match;
	t_array	kp;
	t_room	*r;

	return (false);
	idx[0] = -1;
	while (++idx[0] < f->paths.item_count)
	{
		kp = *(t_array*)ft_ary_get(&f->paths, idx[0]);
		idx[1] = -1;
		match = true;
		while (++idx[1] < path.item_count)
		{
			r = *(t_room**)ft_ary_get(&path, idx[1]);
			match &= path_contains(kp, r);
		}
		if (match)
			return (true);
	}
	return (false);
}

static void	walk(t_farm *f, t_room *r, t_array partial)
{
	t_array	path;
	t_room	*next;
	t_room	**links;

	if (path_subsumed(f, partial))
		return ;
	links = r->links.ptr;
	while (links < &((t_room**)r->links.ptr)[r->links.item_count])
	{
		next = *links++;
		if (path_contains(partial, next))
			continue ;
		path = ft_ary_clone(partial, 0);
		ft_ary_append(&path, &next);
		if (next == f->finish)
			ft_ary_append(&f->paths, &path);
		else
			ft_ary_append(&f->pathq, &path);
	}
	ft_ary_destroy(&partial);
}

void		walk_until(t_farm *f, int num_paths)
{
	size_t	idx;
	t_room	*r;
	t_array	p;

	p = ft_ary_create(sizeof(t_room*));
	walk(f, f->start, p);
	idx = 0;
	while (num_paths < f->paths.item_count)
	{
		p = *(t_array*)ft_ary_get(&f->pathq, idx++);
		r = *(t_room**)ft_ary_get(&p, p.item_count - 1);
		walk(f, r, p);
		if (idx > 32)
		{
			ft_ary_remove_mul(&f->pathq, 0, idx);
			idx = 0;
		}
	}
	ft_ary_remove_mul(&f->pathq, 0, idx);
}
