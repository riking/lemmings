/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 20:36:53 by kyork             #+#    #+#             */
/*   Updated: 2017/01/11 13:44:41 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FARM_H
# define FARM_H

# include <libft.h>
# include <stdbool.h>

/*
** links is a t_array<t_room*>
*/
typedef struct		s_room {
	t_array			links;
	char			*name;
	int				coord_x;
	int				coord_y;
	bool			is_start;
	bool			is_finish;
}					t_room;

/*
** t_farm_layout is received from reading an input file
**
** room_info is a t_array<t_room*>
*/
typedef struct		s_farm_layout {
	t_array		room_info;
	int			ant_count;
}					t_farm_layout;

typedef struct		s_ant {
	t_array		path;
	int			offset;
	int			ant_id;
}					t_ant;

typedef struct		s_farm {
	t_farm_layout	layout;
	t_array			paths;
	t_array			pathq;
	t_room			*start;
	t_room			*finish;
}					t_farm;

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

# define PARSEERR_RET void __attribute__((noreturn))
# define PARSE_ERROR() parse_error(__FILE__, __LINE__)
# define GPARSE_ERROR() parse_error(__FILE__, __LINE__);

PARSEERR_RET		parse_error(char *file, int line);

#endif
