/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 12:16:59 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 17:27:27 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "farm.h"
#include <ft_printf.h>

void		flood_fill(t_room *r)
{
	size_t	i;
	t_room	*it;

	i = 0;
	while (i < r->links.item_count)
	{
		it = *(t_room**)ft_ary_get(&r->links, i);
		if (it->end_dist > r->end_dist + 1)
		{
			it->end_dist = r->end_dist + 1;
			flood_fill(it);
		}
		i++;
	}
}
