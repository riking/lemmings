/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path_room_queue.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:25:20 by kyork             #+#    #+#             */
/*   Updated: 2017/05/04 13:26:40 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

void	search_path_room_queue(t_path *p, t_room *r, t_array *queue)
{
	t_path	new_path;

	new_path = ft_ary_clone(*p, p->item_count + 1);
	ft_ary_append(&new_path, &r);
	ft_ary_append(queue, &new_path);
}
