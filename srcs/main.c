/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:16:11 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 17:26:14 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "farm.h"
#include "parse/type.h"
#include "lemprint/type.h"
#include "search/type.h"
#include "subset/type.h"
#include "antassign/type.h"
#include <libft.h>
#include <ft_printf.h>

static int	num_routes_needed(t_farm *f)
{
	if (max_path(f) == 1)
		return (1);
	return (f->start->end_dist * f->layout.room_info.item_count);
}

static void	run(t_farm *f)
{
	size_t	i;
	t_path	*p;

	parse_layout(&f->layout, 0);
	parse_set_startfinish(f);
	search_setup(f);
	search_workall(f, num_routes_needed(f));
	i = 0;
	ft_dprintf(2, "npaths: %ld\n", f->paths.item_count);
	while (i < f->paths.item_count)
	{
		p = (t_path*)ft_ary_get(&f->paths, i);
		search_print_path(p);
		i++;
	}
	subset_findn(f);
	antassign_do(f);
	i = 0;
	ft_dprintf(2, "path set %ld: (size %ld)\n", i, f->set->paths.item_count);
	while (i < f->set->paths.item_count)
	{
		p = *(t_path**)ft_ary_get(&f->set->paths, i);
		ft_dprintf(2, "path: cost=%d ary=%p %ld\n", p->cost, p->p.ptr, p->p.item_count);
		search_print_path(p);
		i++;
	}
	ft_dprintf(2, "----\n");
	print_layout(&f->layout, 1);
	antassign_print(f, 1);
	antassign_cleanup(f);
	subset_cleanup(f);
	search_cleanup(f);
	parse_cleanup(&f->layout);
}

int			main(int argc, char **argv)
{
	t_farm	f;

	ft_bzero(&f, sizeof(f));
	run(&f);
	(void)argc;
	(void)argv;
	return (0);
}
