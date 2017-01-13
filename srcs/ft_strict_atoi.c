/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strict_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:21:53 by kyork             #+#    #+#             */
/*   Updated: 2017/01/12 15:22:06 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "farm.h"

int		ft_strict_atoi(int *dst, const char *str)
{
	const char			*s;
	unsigned long long	result;
	int					sign;

	while (IS_SPACE(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	result = 0;
	s = str;
	while ('0' <= *s && *s <= '9')
	{
		result = result * 10LL + (unsigned long long)(*s - '0');
		s++;
	}
	if (result > 2147483648LL || (sign == 1 && result == 2147483648LL)
		|| (s - str) > 19 || (*s) != '\0')
		return (1);
	*dst = sign * (int)result;
	return (0);
}
