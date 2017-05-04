/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:01:16 by kyork             #+#    #+#             */
/*   Updated: 2017/05/04 14:34:25 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>

int		parse_rooms(t_farm_layout *layout, char **line, int fd)
{
	int		status;

	layout->directive_tmp = 0;
	while (get_next_line(fd, line) == 1)
	{
		if (ft_strstr(*line, "#") == *line)
			parse_directive(layout, *line);
		else
		{
			status = parse_room(layout, *line);
			if (status == STATUS_NEXTSECTION)
				return (STATUS_NEXTSECTION);
			layout->directive_tmp = 0;
		}
		free(*line);
	}
	if (status)
		PARSE_ERROR("Read error");
	else
		PARSE_ERROR("Unexpected EOF");
}

int		parse_links(t_farm_layout *layout, char **line, int fd)
{
	int		status;

	parse_link(layout, *line);
	free(*line);
	while ((status = get_next_line(fd, line)) == 1)
	{
		if (ft_strcmp(*line, "") == 0)
			return (STATUS_NEXTSECTION);
		if (*line[0] == '#')
			parse_directive(layout, *line);
		else
			parse_link(layout, *line);
	}
	if (status)
		PARSE_ERROR("Read error");
	return (0);
}
