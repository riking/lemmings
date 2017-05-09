/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subset_construct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 14:58:26 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 15:14:33 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>

t_pathset	*subset_clone(t_farm *f, t_pathset *s)
{
	t_pathset	*n;

	n = malloc(sizeof(t_pathset));
	if (s->paths.ptr == 0)
		n->paths = ft_ary_create(sizeof(t_path*));
	else
		n->paths = ft_ary_clone(s->paths, 0);
	n->used_rooms = ft_memdup(s->used_rooms, (f->layout.room_info.item_count
				+ 7) / 8);
	return (n);
}

void		subset_destroy(t_pathset *s)
{
	ft_ary_destroy(&s->paths);
	free(s->used_rooms);
}
