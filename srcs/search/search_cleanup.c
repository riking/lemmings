/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_cleanup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 12:49:35 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 13:00:17 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

void		search_cleanup(t_farm *f)
{
	size_t	i;
	t_path	*itp;

	i = 0;
	while (i < f->pathq.item_count)
	{
		itp = (t_path*)ft_ary_get(&f->pathq, i);
		ft_ary_destroy(&itp->p);
		i++;
	}
	i = 0;
	while (i < f->paths.item_count)
	{
		itp = (t_path*)ft_ary_get(&f->paths, i);
		ft_ary_destroy(&itp->p);
		i++;
	}
	ft_ary_destroy(&f->pathq);
	ft_ary_destroy(&f->paths);
}
