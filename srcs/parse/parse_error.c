/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:19:32 by kyork             #+#    #+#             */
/*   Updated: 2017/05/08 18:06:28 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdarg.h>
#include <ft_printf.h>
#include <stdlib.h>
#include <unistd.h>

PARSEERR_NORET	parse_error(char *file, int line, const char *fmt, ...)
{
	char	*str;
	va_list	args;

	va_start(args, fmt);
	ft_vasprintf(&str, fmt, args);
	va_end(args);
	ft_dprintf(1, "ERROR\n");
	ft_dprintf(2, "%s:%d: %s\n", file, line, str);
	parse_error_debug_break();
	free(str);
	_exit(1);
}

#define VOID_NOINLINE void __attribute__((noinline))

VOID_NOINLINE	parse_error_debug_break(void)
{
}
