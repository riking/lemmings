/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_layout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:25:26 by kyork             #+#    #+#             */
/*   Updated: 2017/05/04 14:37:52 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>

int			parse_ant_count(t_farm_layout *layout, char *line)
{
	if (ft_strict_atoi(&layout->ant_count, line) != 0)
		PARSE_ERROR("Ant count not a number");
	return (0);
}

static void	do_parse_ant_count(t_farm_layout *layout, int fd)
{
	int		status;
	char	*line;

	while ((status = get_next_line(fd, &line)) == 1)
	{
		if (line[0] == '#')
			parse_directive(layout, line);
		else
		{
			parse_ant_count(layout, line);
			free(line);
			return ;
		}
		free(line);
	}
	if (status)
		PARSE_ERROR("Read error");
	else
		PARSE_ERROR("Unexpected EOF");
}

int			parse_layout(t_farm_layout *layout, int fd)
{
	int		status;
	char	*line;

	layout->room_info = ft_ary_create(sizeof(t_room*));
	do_parse_ant_count(layout, fd);
	if (parse_rooms(layout, &line, fd) != STATUS_NEXTSECTION)
		PARSE_ERROR("Bad return from parse_rooms");
	status = parse_links(layout, &line, fd);
	if (status == STATUS_NEXTSECTION)
	{
		free(line);
		status = parse_movements(layout, &line, fd);
	}
	if (status != 0)
		PARSE_ERROR("Did not reach EOF");
	return (0);
}
