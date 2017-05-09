/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:11:41 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 16:56:57 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

static void	add_link(t_farm_layout *layout, t_room *a, t_room *b)
{
	size_t	i;
	t_room	*it;
	t_array	sentinel;

	sentinel = FT_ARY_NULL;
	sentinel.ptr = LINK_OUTPUT_SENTINEL;
	i = 0;
	while (i < b->links.item_count)
	{
		it = *(t_room**)ft_ary_get(&b->links, i);
		if (it == a)
		{
			ft_ary_set(&b->link_comments, &layout->tmp_comments, i);
			return ;
		}
		i++;
	}
	ft_ary_append(&a->links, &b);
	ft_ary_append(&a->link_comments, &layout->tmp_comments);
	ft_ary_append(&b->links, &a);
	ft_ary_append(&b->link_comments, &sentinel);
}

int			parse_link(t_farm_layout *layout, char *line)
{
	char	**split;
	t_room	*r1;
	t_room	*r2;

	split = ft_strsplit(line, '-');
	if (!(split[0] && split[1] && !split[2]))
		PARSE_ERROR("Wrong number of segments for link");
	r1 = find_room(layout, split[0]);
	r2 = find_room(layout, split[1]);
	if (!r1 || !r2)
		PARSE_ERROR("Link parts are not room names");
	add_link(layout, r1, r2);
	layout->tmp_comments = FT_ARY_NULL;
	ft_strtab_destroy(split);
	return (0);
}
