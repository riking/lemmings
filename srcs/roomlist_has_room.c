/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roomlist_has_room.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:38:39 by kyork             #+#    #+#             */
/*   Updated: 2017/05/04 14:44:20 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "farm.h"

bool	roomlist_has_room(t_array *rlist, t_room *room)
{
	t_room	*it;
	size_t	i;

	i = 0;
	while (i < rlist->item_count)
	{
		it = *(t_room**)ft_ary_get(rlist, i);
		if (it == room)
			return (true);
		i++;
	}
	return (false);
}
