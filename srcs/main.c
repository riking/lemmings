/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:16:11 by kyork             #+#    #+#             */
/*   Updated: 2017/05/04 14:57:07 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "farm.h"
#include "search/type.h"
#include <libft.h>

int		main(int argc, char **argv)
{
	t_farm	f;

	ft_bzero(&f, sizeof(f));
	parse_layout(&f.layout, 0);
	parse_set_startfinish(&f);
	search_setup(&f);
	search_workall(&f);
	size_t i = 0;
	while (i < f.paths.item_count)
	{
		t_path *p = ft_ary_get(&f.paths, i);
		search_print_path(p);
		i++;
	}
	int debugger = 1;
	(void)argc;
	(void)argv;
	return (debugger);
}
