/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathcmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:02:51 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 15:06:56 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <unistd.h>

/*
** compare function for t_array<t_path>
*/

int			subset_pathcmp(void *left, void *right, size_t size, void *data)
{
	t_path	*a;
	t_path	*b;

	if (size != sizeof(t_path))
		_exit(30);
	a = (t_path*)left;
	b = (t_path*)right;
	(void)data;
	if (a->p.item_count < b->p.item_count)
		return (-1);
	if (a->p.item_count > b->p.item_count)
		return (1);
	return (0);
}
