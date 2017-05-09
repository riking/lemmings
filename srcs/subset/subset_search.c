/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subset_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 14:45:32 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 17:26:28 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <ft_printf.h>

static int submit(t_farm *f, t_pathset *sp)
{
	t_pathset	*s;

	s = subset_clone(f, sp);
	f->set = s;
	return (2);
}

int			subset_search(t_farm *f, t_pathset *sp)
{
	size_t		i;
	int			status;
	t_path		*p;
	t_pathset	*s;

	if (sp->paths.item_count == (size_t)f->npath_target)
		return (submit(f, sp));
	i = 0;
	while (i < f->paths.item_count)
	{
		p = (t_path*)ft_ary_get(&f->paths, i);
		i++;
		if (subset_conflict_path(sp, p))
			continue ;
		s = subset_clone(f, sp);
		subset_add_path(s, p);
		status = subset_search(f, s);
		subset_destroy(s);
		if (status == 2)
			return (2);
	}
	return (0);
}
