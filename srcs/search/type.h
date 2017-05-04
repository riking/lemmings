/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:57:14 by kyork             #+#    #+#             */
/*   Updated: 2017/05/04 13:38:16 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCH_TYPE_H
# define SEARCH_TYPE_H

# include "../farm.h"

void		search_print_path(t_path *p);
void		search_path_room_queue(t_path *p, t_room *r, t_array *pathq);
void		search_work_path(t_farm *f, t_path *p);
void		search_workall(t_farm *f);
void 		search_setup(t_farm *f);
void		search_cleanup(t_farm *f);

#endif
