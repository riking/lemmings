/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moverec_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 11:08:33 by kyork             #+#    #+#             */
/*   Updated: 2017/05/03 11:10:47 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>

t_moverecord	*moverec_new(void)
{
	t_moverecord	*r;
	t_array			turns;

	turns = ft_ary_create(sizeof(t_moverecord_turn));
	r = malloc(sizeof(t_moverecord));
	r->turns = turns;
	return (r);
}
