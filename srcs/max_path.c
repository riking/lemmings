/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 14:06:18 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 14:07:33 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "farm.h"

int		max_path(t_farm *f)
{
	size_t	n;

	n = f->start->links.item_count;
	if (f->finish->links.item_count < n)
		n = f->finish->links.item_count;
	return ((int)n);
}
