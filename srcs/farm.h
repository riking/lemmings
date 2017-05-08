/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 20:36:53 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 13:22:45 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FARM_H
# define FARM_H

# include <libft.h>
# include <stdbool.h>
# include <stdint.h>

/*
** t_roomlist is a t_array<t_room*>
*/
typedef t_array		t_roomlist;

/*
** id is assigned in order of creation, used only internally
*/
typedef struct		s_room {
	t_roomlist		links;
	char			*name;
	int				coord_x;
	int				coord_y;
	int				end_dist;
	int				id;
	bool			is_start;
	bool			is_finish;
}					t_room;

/*
** t_farm_layout is received from reading an input file
**
** room_info is a t_array<t_room*>
*/
typedef struct		s_farm_layout {
	t_roomlist	room_info;
	int			directive_tmp;
	int			ant_count;
}					t_farm_layout;

/*
** paths, pathq: t_array<t_path>
** pathq owned by search/
** paths is result of path searching
** sets: t_array<t_pathset>
*/

typedef struct		s_farm {
	t_farm_layout	layout;
	t_array			paths;
	t_array			pathq;
	t_array			sets;
	t_room			*start;
	t_room			*finish;
}					t_farm;

/*
** p: roomlist
** cost of 0 = not calculated; use search_path_cost() as a getter
*/
typedef struct		s_path {
	int			cost;
	t_roomlist	p;
}					t_path;	

int					search_path_cost(t_farm *f, t_path *p);
bool				paths_conflict(t_path *a, t_path *b);

typedef struct		s_ant {
	t_path		*path;
	int			offset;
	int			ant_id;
}					t_ant;

/*
** used_rooms: bitfield; byte size = len(layout) + 7 / 8
** paths: t_array<t_path*>
*/
typedef struct		s_pathset {
	t_array		paths;
	uint8_t		*used_rooms;
}					t_pathset;

/*
** Nothing seems to be better than identifying shortest N paths
**
** Overview:
** - breadth-first search, identify all paths (w/ optimizations)
** - identify shortest 1 nonconflict paths, shortest 2 nonconflict paths, shortest
**       3 nonconflict paths, until no such set?
** - 
*/

t_array				walk_map(t_farm *f);
int					ft_strict_atoi(int *dst, const char *str);
void				flood_fill(t_room *r);

/*
** set a breakpoint to debug parse errors
*/
void				parse_error_debug_break(void);

int					parse_layout(t_farm_layout *layout, int fd);
int					parse_set_startfinish(t_farm *f);

t_room				*find_room(t_farm_layout *layout, char *name);

bool				roomlist_has_room(t_roomlist *rlist, t_room *room);

#endif
