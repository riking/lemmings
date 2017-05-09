/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:37:35 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 17:12:15 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANTASSIGN_TYPE_H
# define ANTASSIGN_TYPE_H

# include "../farm.h"

void		antassign_tick(t_farm *f, size_t finish_time);
void		antassign_do(t_farm *f);
void		antassign_print(t_farm *f, int fd);
void		antassign_cleanup(t_farm *f);

#endif
