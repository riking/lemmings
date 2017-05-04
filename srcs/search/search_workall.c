/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_workall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:28:00 by kyork             #+#    #+#             */
/*   Updated: 2017/05/04 15:04:45 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <ft_printf.h>

void		search_workall(t_farm *f)
{
	size_t	idx;
	t_path	p;

	while (f->pathq.item_count != 0)
	{
		idx = f->pathq.item_count - 1;
		p = *(t_path*)ft_ary_get(&f->pathq, idx);
		ft_printf("working path #%ld\n", idx);
		search_work_path(f, &p);
		ft_ary_destroy(&p);
		ft_ary_remove(&f->pathq, idx);
	}
	ft_ary_destroy(&f->pathq);
	f->pathq = FT_ARY_NULL;
}
