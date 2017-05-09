/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 16:24:55 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 16:27:01 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMPRINT_TYPE_H
# define LEMPRINT_TYPE_H

# include "../farm.h"

void				print_comments(t_array *comments, int fd);
void				print_layout(t_farm_layout *layout, int fd);
void				print_room(t_farm_layout *layout, t_room *r, int fd);
void				print_room_links(t_farm_layout *layout, t_room *r, int fd);

#endif
