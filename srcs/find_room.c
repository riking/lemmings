/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:40:52 by kyork             #+#    #+#             */
/*   Updated: 2017/05/04 14:47:47 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "farm.h"

t_room	*find_room(t_farm_layout *layout, char *name)
{
	size_t	i;
	t_room	*it;

	i = 0;
	while (i < layout->room_info.item_count)
	{
		it = *(t_room**)ft_ary_get(&layout->room_info, i);
		if (0 == ft_strcmp(name, it->name))
			return (it);
		i++;
	}
	return (NULL);
}
