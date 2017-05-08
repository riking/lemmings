/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path_room_queue.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:25:20 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 12:04:56 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

void	search_path_room_queue(t_path *p, t_room *r, t_array *queue)
{
	t_path	new_path;

	new_path.p = ft_ary_clone(p->p, p->p.item_count + 1);
	new_path.cost = 0;
	ft_ary_append(&new_path.p, &r);
	ft_ary_append(queue, &new_path);
}
