/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 13:15:37 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 15:36:30 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSET_TYPE_H
# define SUBSET_TYPE_H

# include "../farm.h"

void		subset_setup(t_farm *f);
bool		subset_room_has(t_pathset *s, t_room *r);
void		subset_room_set(t_pathset *s, t_room *r);
void		subset_room_clear(t_pathset *s, t_room *r);

void		subset_add_path(t_pathset *s, t_path *p);
bool		subset_conflict_path(t_pathset *s, t_path *p);

t_pathset	*subset_clone(t_farm *f, t_pathset *s);
void		subset_destroy(t_pathset *s);

int			subset_search(t_farm *f, t_pathset *sp);
void		subset_findn(t_farm *f);
void		subset_cleanup(t_farm *f);

/*
** compare function for t_array<t_path>
*/
int			subset_pathcmp(void *l, void *r, size_t size, void *data);

#endif
