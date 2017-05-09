/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_directive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:43:49 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 16:46:03 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

/*
** in charge of storing comments
*/

int		parse_directive(t_farm_layout *layout, char *line)
{
	char	*dup;

	if (line[0] != '#')
		PARSE_ERROR("parse_directive: line is not comment/directive");
	if (!layout->tmp_comments.ptr)
		layout->tmp_comments = ft_ary_create(sizeof(char*));
	dup = ft_strdup(line);
	ft_ary_append(&layout->tmp_comments, &dup);
	if (line[1] != '#')
		return (0);
	if (ft_strcmp(line, "##start") == 0)
		layout->directive_tmp |= ATTR_START;
	else if (ft_strcmp(line, "##end") == 0)
		layout->directive_tmp |= ATTR_FINSH;
	else
		;
	return (0);
}
