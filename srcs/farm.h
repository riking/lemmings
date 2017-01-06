/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 20:36:53 by kyork             #+#    #+#             */
/*   Updated: 2017/01/06 12:35:56 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FARM_H
# define FARM_H

# include <stdbool.h>

typedef struct		s_room_m {
	char	*name;
	int		coord_x;
	int		coord_y;
	bool	is_start;
	bool	is_end;
}					t_room_m;

/*
** links is a t_array<t_room*>
** when_occupied is an int array, sized farm.max_time, where each element is an
** ant's number if they're in the room at that time step, or 0 if none is.
*/

typedef struct		s_room {
	t_array			links;
	t_room_m		meta;
	int				*when_occupied;
}					t_room;

/*
** t_farm_layout is received from reading an input file
**
** room_info is a t_array<t_room_m>
*/
typedef struct		s_farm_layout {
	t_array		room_info;
	int			ant_count;
}					t_farm_layout;

/*
** rooms is a t_array<t_room*>
*/
typedef struct		s_path {
	t_array		rooms;
}					t_path;

typedef struct		s_ant {
	t_path		path;
	int			offset;
	int			ant_id;
}					t_ant;

typedef struct		s_farm {
	t_farm_layout	layout;
	t_array			paths;
	t_room			*start;
	t_room			*finish;
}					t_farm;

/*
** Nothing better than identifying shortest N paths
**
** Overview:
** - branching search, identify all paths (w/ optimizations)
** - identify shortest 1 nonconflict paths, shortest 2 nonconflict paths, shortest 3 nonconflict paths, until no such set?
** - 
*/

t_array walk_map(t_farm *f);

#endif
