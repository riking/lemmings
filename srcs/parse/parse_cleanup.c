/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cleanup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 12:54:33 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 13:10:43 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>

void		parse_cleanup(t_farm_layout *layout)
{
	size_t	i;
	t_room	*it;

	i = 0;
	while (i < layout->room_info.item_count)
	{
		it = *(t_room**)ft_ary_get(&layout->room_info, i);
		ft_ary_destroy(&it->links);
		free(it->name);
		free(it);
		i++;
	}
	ft_ary_destroy(&layout->room_info);
}
