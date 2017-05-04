/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_print_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:35:15 by kyork             #+#    #+#             */
/*   Updated: 2017/05/04 14:44:41 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <ft_printf.h>

void		search_print_path(t_path *p)
{
	size_t		i;
	t_room		*r;

	i = 0;
	while (i < p->item_count)
	{
		r = *(t_room**)ft_ary_get(p, i);
		ft_printf("%s", r->name);
		i++;
		if (i != p->item_count)
			ft_printf("-");
	}
	ft_printf("\n");
}
