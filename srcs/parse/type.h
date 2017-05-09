/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:40:55 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 16:24:48 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_TYPE_H
# define PARSE_TYPE_H

# include "../farm.h"

# define ATTR_START (1 << 1)
# define ATTR_FINSH (1 << 2)

# define STATUS_NEXTSECTION 2

# define PARSEERR_NORET void __attribute__((noreturn))
# define PARSE_ERROR(reason) parse_error(__FILE__, __LINE__, reason)
# define PARSE_ERRORF(f, ...) parse_error(__FILE__, __LINE__, f, __VA_ARGS__)
# define GPARSE_ERROR() parse_error(__FILE__, __LINE__, "");

PARSEERR_NORET		parse_error(char *file, int line, const char *fmt, ...);

int					parse_layout(t_farm_layout *layout, int fd);
int					parse_rooms(t_farm_layout *layout, char **line, int fd);
int					parse_links(t_farm_layout *layout, char **line, int fd);
int					parse_movements(t_farm_layout *layout, char **line, int fd);

int					parse_set_startfinish(t_farm *f);

int					parse_directive(t_farm_layout *layout, char *line);
int					parse_ant_count(t_farm_layout *layout, char *line);
int					parse_room(t_farm_layout *layout, char *line);
int					parse_link(t_farm_layout *layout, char *line);

void				parse_cleanup(t_farm_layout *layout);

#endif
