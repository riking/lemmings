/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 20:36:53 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 16:57:36 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FARM_H
# define FARM_H

# include <libft.h>
# include <stdbool.h>
# include <stdint.h>

# define LINK_OUTPUT_SENTINEL ((void*)1)

/*
** t_roomlist is a t_array<t_room*>
*/
typedef t_array		t_roomlist;

/*
** id is assigned in order of creation, used only internally
** comments: t_array<owned char*>
** link_comments: t_array<t_array<owned char*>>
*/
typedef struct		s_room {
	t_roomlist		links;
	t_array			comments;
	t_array			link_comments;
	char			*name;
	int				coord_x;
	int				coord_y;
	int				end_dist;
	int				id;
	bool			is_start;
	bool			is_finish;
}					t_room;

/*
** p: roomlist
** cost of 0 = not calculated; use search_path_cost() as a getter
*/
typedef struct		s_path {
	int			cost;
	t_roomlist	p;
}					t_path;

/*
** used_rooms: bitfield; byte size = len(layout) + 7 / 8
** paths: t_array<t_path*>
*/
typedef struct		s_pathset {
	t_array		paths;
	uint8_t		*used_rooms;
}					t_pathset;

/*
** t_farm_layout is received from reading an input file
**
** room_info is a t_array<owned t_room*>
** comment_lines is a t_array<char*>
*/
typedef struct		s_farm_layout {
	t_roomlist	room_info;
	t_array		tmp_comments;
	int			directive_tmp;
	t_array		antcount_comments;
	int			ant_count;
	t_array		trail_comments;
}					t_farm_layout;

/*
** paths, pathq: t_array<t_path>
** pathq owned by search/
** paths is result of path searching
** sets: t_array<t_pathset>
** ants: t_array<t_ant>
*/

typedef struct		s_farm {
	t_farm_layout	layout;
	t_room			*start;
	t_room			*finish;
	t_array			paths;
	t_array			pathq;
	t_pathset		*set;
	int				npath_target;
	t_array			ants;
}					t_farm;

int					search_path_cost(t_farm *f, t_path *p);
bool				paths_conflict(t_path *a, t_path *b);

typedef struct		s_ant {
	t_path		*path;
	int			offset;
	int			ant_id;
}					t_ant;

/*
** Nothing seems to be better than identifying shortest N paths
**
** Overview:
** - breadth-first search, identify all paths (w/ optimizations)
** - identify shortest 1 nonconflict paths, shortest 2 nonconflict paths
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

/*
** max_path: max(start.links, end.links)
*/
int					max_path(t_farm *f);

bool				roomlist_has_room(t_roomlist *rlist, t_room *room);

#endif
