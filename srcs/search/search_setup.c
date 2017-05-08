/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:07:28 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 12:10:07 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

void search_setup(t_farm *f)
{
	t_path	p;

	f->paths = ft_ary_create(sizeof(t_path));
	f->pathq = ft_ary_create(sizeof(t_path));
	p.p = ft_ary_create(sizeof(t_room*));
	p.cost = 1;
	ft_ary_append(&p.p, &f->start);
	ft_ary_append(&f->pathq, &p);
}
