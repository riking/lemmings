/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 12:14:16 by kyork             #+#    #+#             */
/*   Updated: 2017/01/06 14:54:01 by kyork            ###   ########.fr       */
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
	int		idx;
	t_array	path;
	t_room	*next;

	idx = -1;
	if (!path_subsumed(f, partial))
		while (++idx < r->links.item_count)
		{
			next = *(t_room**)ft_ary_get(&r->links, idx);
			if (path_contains(partial, next))
				continue ;
			path = ft_ary_clone(partial, 0);
			ft_ary_append(&path, &next);
			if (next == f->finish)
				ft_ary_append(&f->paths, &path);
			else
				walk(f, next, path);
		}
	ft_ary_destroy(&partial);
}

