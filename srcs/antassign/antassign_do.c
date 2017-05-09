/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antassign_do.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 17:08:36 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 17:21:16 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

void		antassign_do(t_farm *f)
{
	size_t	tick;

	f->ants = ft_ary_create(sizeof(t_ant));
	tick = 1;
	while (f->ants.item_count < (unsigned long)f->layout.ant_count)
	{
		antassign_tick(f, tick);
		tick++;
	}
	while (f->ants.item_count > (unsigned long)f->layout.ant_count)
		ft_ary_poplast(&f->ants);
}
