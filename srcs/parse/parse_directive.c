/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_directive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:43:49 by kyork             #+#    #+#             */
/*   Updated: 2017/05/04 14:32:37 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

int		parse_directive(t_farm_layout *layout, char *line)
{
	if (line[0] != '#')
		PARSE_ERROR("parse_directive: line is not comment/directive");
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
