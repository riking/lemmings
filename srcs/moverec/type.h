/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 11:03:36 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 14:09:41 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEREC_TYPE_H
# define MOVEREC_TYPE_H

# include "../farm.h"

typedef struct		s_antmove {
	t_room	*from;
	t_room	*to;
}					t_antmove;

typedef struct		s_moverecord_turn {
	t_array	ant_moves;
}					t_moverecord_turn;

typedef struct		s_moverecord {
	t_array	turns;
}					t_moverecord;

/*
** add: add a new movement to the current turn
** next: advance to the next turn
** dump: write to file descriptor
*/

t_moverecord		*moverec_new(void);
int					moverec_parseline(
		t_moverecord *r,
		t_farm *f,
		char *const line);
void				moverec_add(t_moverecord *r, t_room *from, t_room *to);
void				moverec_next(t_moverecord *r);
void				moverec_dump(t_moverecord *r, int fd);
void				moverec_destroy(t_moverecord *r);

#endif
