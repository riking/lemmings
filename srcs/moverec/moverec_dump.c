/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moverec_dump.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 11:16:00 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 14:09:18 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <ft_printf.h>

static void		moverec_dumpturn(t_moverecord_turn *t, int fd)
{
	size_t		i;
	t_antmove	*it;

	i = 0;
	while (i < t->ant_moves.item_count)
	{
		it = ft_ary_get(&t->ant_moves, i);
		ft_dprintf(fd, "L%s-%s", it->from->name, it->to->name);
		i++;
		if (i == t->ant_moves.item_count)
		{
			ft_dprintf(fd, "\n");
			return ;
		}
		else
			ft_dprintf(fd, " ");
	}
}

void			moverec_dump(t_moverecord *r, int fd)
{
	size_t				i;
	t_moverecord_turn	*it;

	i = 0;
	while (i < r->turns.item_count)
	{
		it = ft_ary_get(&r->turns, i);
		moverec_dumpturn(it, fd);
		i++;
	}
}
