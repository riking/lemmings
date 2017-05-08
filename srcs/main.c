/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:16:11 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 13:57:54 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "farm.h"
#include "search/type.h"
#include "parse/type.h"
#include <libft.h>

static int	num_routes_needed(t_farm *f)
{
	if (f->start->links.item_count == 1 || f->finish->links.item_count == 1)
		return (1);
	return (f->start->end_dist * f->layout.room_info.item_count);
}

static void	run(t_farm *f)
{
	parse_layout(&f->layout, 0);
	parse_set_startfinish(f);
	search_setup(f);
	search_workall(f, num_routes_needed(f));
	size_t i = 0;
	while (i < f->paths.item_count)
	{
		t_path *p = ft_ary_get(&f->paths, i);
		search_print_path(p);
		i++;
	}
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
