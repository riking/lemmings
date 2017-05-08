/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 13:15:37 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 13:33:06 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSET_TYPE_H
# define SUBSET_TYPE_H

# include "../farm.h"

void		subset_setup(t_farm *f);
bool		subset_room_has(t_pathset *s, t_room *r);
void		subset_room_set(t_pathset *s, t_room *r);
void		subset_room_clear(t_pathset *s, t_room *r);

void		subset_add_path(t_pathset *s, t_path *p, bool add);
bool		subset_conflict_path(t_pathset *s, t_path *p);

t_pathset	*subset_clone(t_pathset *s);
void		subset_destroy(t_pathset *s);

int			subset_cmp(t_pathset *a, t_pathset *b);

#endif
