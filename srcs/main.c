/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:16:11 by kyork             #+#    #+#             */
/*   Updated: 2017/01/17 15:01:13 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "farm.h"
#include <libft.h>

int		main(int argc, char **argv)
{
	t_farm	f;

	ft_bzero(&f, sizeof(f));
	parse_layout(&f.layout, 0);
	int debugger = 1;
	(void)argc;
	(void)argv;
	return (debugger);
}
