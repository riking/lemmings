/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cleanup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 12:54:33 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 17:35:31 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>
#include <ft_printf.h>

/*
** destroy_comments behaves correctly for FT_ARY_NULL
*/

static void	destroy_comments(t_array *a)
{
	size_t	i;
	char	*str;

	i = 0;
	while (i < a->item_count)
	{
		str = *(char**)ft_ary_get(a, i);
		free(str);
		i++;
	}
	ft_ary_destroy(a);
}

static void	destroy_room(t_room *r)
{
	size_t	i;
	t_array	*com;

	ft_ary_destroy(&r->links);
	destroy_comments(&r->comments);
	i = 0;
	while (i < r->link_comments.item_count)
	{
		com = (t_array*)ft_ary_get(&r->link_comments, i);
		destroy_comments(com);
		i++;
	}
	ft_ary_destroy(&r->link_comments);
	free(r->name);
	free(r);
}

void		parse_cleanup(t_farm_layout *layout)
{
	size_t	i;
	t_room	*it;

	i = 0;
	while (i < layout->room_info.item_count)
	{
		it = *(t_room**)ft_ary_get(&layout->room_info, i);
		destroy_room(it);
		i++;
	}
	ft_ary_destroy(&layout->room_info);
	destroy_comments(&layout->antcount_comments);
	destroy_comments(&layout->trail_comments);
}
