/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_conflict.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 12:30:41 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 12:39:14 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "farm.h"

bool		paths_conflict(t_path *a, t_path *b)
{
	size_t		i;
	t_room		*it;

	i = 0;
	while (i < a->p.item_count)
	{
		it = *(t_room**)ft_ary_get(&a->p, i);
		if (!it->is_start && !it->is_finish)
			if (roomlist_has_room(&b->p, it))
				return (true);
		i++;
	}
	return (false);
}
