/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antassign_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 17:12:42 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 17:30:40 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <ft_printf.h>

static bool	print_move(t_ant *a, size_t tick, int fd, bool addspace)
{
	ssize_t	path_pos;
	t_room	*r;

	path_pos = ((ssize_t)tick) - a->offset;
	if (path_pos <= 0 || path_pos >= (ssize_t)a->path->p.item_count)
		return (false);
	r = *(t_room**)ft_ary_get(&a->path->p, path_pos);
	if (addspace)
		ft_dprintf(fd, " ");
	ft_dprintf(fd, "L%d-%s", a->ant_id, r->name);
	return (true);
}

static bool	antassign_printtick(t_farm *f, size_t tick, int fd)
{
	size_t	i;
	t_ant	*a;
	bool	any;

	i = 0;
	any = false;
	ft_dprintf(fd, "\n");
	while (i < f->ants.item_count)
	{
		a = (t_ant*)ft_ary_get(&f->ants, i);
		any |= print_move(a, tick, fd, any);
		i++;
	}
	return (any);
}

void	antassign_print(t_farm *f, int fd)
{
	size_t	tick;
	bool	printed;

	tick = 1;
	printed = true;
	while (printed)
		printed = antassign_printtick(f, tick++, fd);
}
