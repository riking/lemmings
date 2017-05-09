/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:51:23 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 16:17:46 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <ft_guard.h>
#include <limits.h>

int		parse_room(t_farm_layout *layout, char *line)
{
	char	**split;
	t_room	*room;

	if (ft_strstr(line, "-") != NULL)
		return (STATUS_NEXTSECTION);
	split = ft_strsplit(line, ' ');
	if (!(split[0] && split[1] && split[2] && !split[3]))
		PARSE_ERROR("wrong number of fields in room definition");
	room = ft_memalloc(sizeof(t_room));
	ZGUARD(GPARSE_ERROR(), ft_strict_atoi(&room->coord_x, split[1]));
	ZGUARD(GPARSE_ERROR(), ft_strict_atoi(&room->coord_y, split[2]));
	room->name = ft_strdup(split[0]);
	room->links = ft_ary_create(sizeof(t_room*));
	if (layout->directive_tmp & ATTR_START)
		room->is_start = true;
	if (layout->directive_tmp & ATTR_FINSH)
		room->is_finish = true;
	room->id = layout->room_info.item_count;
	room->end_dist = INT_MAX;
	room->comments = layout->tmp_comments;
	room->link_comments = ft_ary_create(sizeof(t_array));
	ft_ary_append(&layout->room_info, &room);
	ft_strtab_destroy(split);
	return (0);
}
