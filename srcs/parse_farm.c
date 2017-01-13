/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_farm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:17:17 by kyork             #+#    #+#             */
/*   Updated: 2017/01/12 15:17:17 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_printf.h>
#include <ft_guard.h>
#include "farm.h"

#define ATTR_START  (1 << 1)
#define ATTR_FINISH (1 << 2)

#define STATUS_NEXTSECTION 2

static int	parse_directive(int *attrs, char *line)
{
	if (line[1] != '#')
		return (0);
	if (ft_strcmp(line, "##start") == 0)
		*attrs |= ATTR_START;
	else if (ft_strcmp(line, "##end") == 0)
		*attrs |= ATTR_FINISH;
	else
		;
	return (0);
}

static int	parse_room(t_farm_layout *layout, char *line, int attrs)
{
	char		**split;
	t_room		*room;

	split = ft_strsplit(line, ' ');
	if (split[0] && !split[1] && (ft_strstr(line, "-") != NULL))
	{
		ft_strtab_destroy(split);
		return (STATUS_NEXTSECTION);
	}
	if (!(split[0] && split[1] && split[2] && !split[3]))
		PARSE_ERROR();
	NGUARD(GPARSE_ERROR(), room = malloc(sizeof(t_room)));
	NGUARD(GPARSE_ERROR(), room->name = ft_strdup(split[0]));
	room->links = ft_ary_create(sizeof(t_room*));
	NGUARD(GPARSE_ERROR(), room->links.ptr);
	ZGUARD(GPARSE_ERROR(), ft_strict_atoi(&room->coord_x, split[1]));
	ZGUARD(GPARSE_ERROR(), ft_strict_atoi(&room->coord_y, split[2]));
	if (attrs & ATTR_START)
		room->is_start = true;
	if (attrs & ATTR_FINISH)
		room->is_finish = true;
	ZGUARD(GPARSE_ERROR(), ft_ary_append(&layout->room_info, &room));
	ft_strtab_destroy(split);
	return (0);
}

int			parse_rooms(t_farm_layout *layout, char **line, int fd)
{
	int		status;
	int		attrs;

	attrs = 0;
	while (get_next_line(fd, line) == 1)
	{
		if (ft_strstr(*line, "#") == *line)
			parse_directive(&attrs, *line);
		else
		{
			status = parse_room(layout, *line, attrs);
			if (status == STATUS_NEXTSECTION)
				return (STATUS_NEXTSECTION);
			else if (status != 0)
				return (1);
			attrs = 0;
		}
		free(*line);
	}
	return (1);
}

static t_room	*find_room(t_farm_layout *layout, char *name)
{
	t_room	**rooms;
	int		idx;

	rooms = layout->room_info.ptr;
	idx = 0;
	while (idx < layout->room_info.item_count)
	{
		if (0 == ft_strcmp(name, rooms[idx]->name))
			return (rooms[idx]);
	}
	return (NULL);
}

static int	parse_link(t_farm_layout *layout, char *line)
{
	char	**split;
	t_room	*r1;
	t_room	*r2;

	split = ft_strsplit(line, '-');
	if (!(split[0] && split[1] && !split[2]))
		return (1);
	r1 = find_room(layout, split[0]);
	r2 = find_room(layout, split[1]);
	if (!r1 || !r2)
		return (1);
	ft_ary_append(&r1->links, &r2);
	ft_ary_append(&r2->links, &r1);
	return (0);
}

int 		parse_links(t_farm_layout *layout, char **line, int fd)
{
	int		status;

	while ((status = get_next_line(fd, line)) == 1)
	{
		if (*line[0] == 'L')
			return (STATUS_NEXTSECTION);

	}
	return (status);
}


#ifdef DEBUG

void		parse_error(char *file, int line)
{
	ft_dprintf(1, "ERROR\n");
	ft_dprintf(2, "parse error at %s:%d\n", file, line);
	exit(1);
}

#else

void		parse_error(char *file, int line)
{
	ft_dprintf(1, "ERROR\n");
	(void)file;
	(void)line;
	exit(1);
}

#endif

/*
** TODO - allow parsing ants
*/

int			parse_layout(t_farm_layout *layout, int fd)
{
	int		status;
	char	*line;

	if (get_next_line(fd, &line) != 1)
		return (1);
	if (ft_strict_atoi(&layout->ant_count, line) != 0)
		PARSE_ERROR();
	free(line);
	if (parse_rooms(layout, &line, fd) != STATUS_NEXTSECTION)
		PARSE_ERROR();
	if (parse_link(layout, line) != 0)
		PARSE_ERROR();
	free(line);
	status = parse_links(layout, &line, fd);
	if (status == STATUS_NEXTSECTION)
	{
		PARSE_ERROR();
	}
	else if (status != 0)
		PARSE_ERROR();
}
