/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moverec_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 11:14:00 by kyork             #+#    #+#             */
/*   Updated: 2017/05/03 11:15:48 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

void	moverec_next(t_moverecord *r)
{
	t_moverecord_turn to_add;

	to_add.ant_moves = ft_ary_create(sizeof(t_antmove));
	ft_ary_append(&r->turns, &to_add);
}
