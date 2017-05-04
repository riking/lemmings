/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:11:41 by kyork             #+#    #+#             */
/*   Updated: 2017/05/04 14:14:18 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

int		parse_link(t_farm_layout *layout, char *line)
{
	char	**split;
	t_room	*r1;
	t_room	*r2;

	split = ft_strsplit(line, '-');
	if (!(split[0] && split[1] && !split[2]))
		PARSE_ERROR("Wrong number of segments for link");
	r1 = find_room(layout, split[0]);
	r2 = find_room(layout, split[1]);
	if (!r1 || !r2)
		PARSE_ERROR("Link parts are not room names");
	ft_ary_append(&r1->links, &r2);
	ft_ary_append(&r2->links, &r1);
	ft_strtab_destroy(split);
	return (0);
}
