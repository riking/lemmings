/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subset_findn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 14:55:02 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 17:29:21 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <ft_printf.h>
#include <stdlib.h>

#define UNUSED_DEBUG(...)

void	subset_findn(t_farm *f)
{
	t_pathset	root;
	int			status;

	root.used_rooms = ft_memalloc((f->layout.room_info.item_count + 7) / 8);
	root.paths = FT_ARY_NULL;
	ft_ary_sort(&f->paths, &subset_pathcmp, NULL);
	f->set = NULL;
	f->npath_target = max_path(f);
	while (f->npath_target > 0)
	{
		UNUSED_DEBUG("[subset] attempting n=%d\n", f->npath_target);
		if ((status = subset_search(f, &root)) == 2)
			break ;
		UNUSED_DEBUG("[subset] could not find path set of size %d\n", f->npath_target);
		f->npath_target--;
	}
	free(root.used_rooms);
	if (f->set == 0)
	{
		ft_printf("ERROR\n");
		exit(1);
	}
}
