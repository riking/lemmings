/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moverec_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 11:11:01 by kyork             #+#    #+#             */
/*   Updated: 2017/05/03 11:13:34 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

void	moverec_add(t_moverecord *r, t_room *from, t_room *to)
{
	t_moverecord_turn	*turn;
	t_antmove			to_add;

	if (r->turns.item_count == 0)
		return ;
	to_add.from = from;
	to_add.to = to;
	turn = (t_moverecord_turn*)ft_ary_get(&r->turns, r->turns.item_count - 1);
	ft_ary_append(&turn->ant_moves, &to_add);
}
