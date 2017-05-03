/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moverec_parseline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 11:26:46 by kyork             #+#    #+#             */
/*   Updated: 2017/05/03 11:41:10 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>

static int	moverec_parsemove(t_moverecord *r, t_farm *f,
		t_antmove *m,
		char * const move)
{
	char	*dash;
	char	*name;

	if (move[0] != 'L')
		return (-1);
	dash = ft_strchr(move, '-');
	if (!dash)
		return (-1);
	name = ft_strsub(move, 1, (dash - move));
	m->from = find_room(&f->layout, name);
	free(name);
	name = ft_strsub(move, (dash - move) + 1, 99999);
	m->to = find_room(&f->layout, name);
	free(name);
	if (!m->from || !m->to)
		return (-1);
	return (0);
}

int			moverec_parseline(t_moverecord *r, t_farm *f, char * const line)
{
	char		**movetab;
	int			i;
	t_antmove	m;

	moverec_next(r);
	movetab = ft_strsplit(line, ' ');
	i = 0;
	while (movetab[i])
	{
		if (moverec_parsemove(r, f, &m, movetab[i]) < 0)
		{
			ft_strtab_destroy(movetab);
			return (-1);
		}
		moverec_add(r, m.from, m.to);
		i++;
	}
	return (0);
}
