/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moverec_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 11:20:02 by kyork             #+#    #+#             */
/*   Updated: 2017/05/03 11:21:55 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>

static void		destroy_turn(t_moverecord_turn *t)
{
	ft_ary_destroy(&t->ant_moves);
}

void			moverec_destroy(t_moverecord *r)
{
	size_t				i;
	t_moverecord_turn	*it;

	i = 0;
	while (i < r->turns.item_count)
	{
		it = ft_ary_get(&r->turns, i);
		destroy_turn(it);
		i++;
	}
	ft_ary_destroy(&r->turns);
	free(r);
}
