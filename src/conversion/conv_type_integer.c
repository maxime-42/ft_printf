/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:08:03 by mkayumba          #+#    #+#             */
/*   Updated: 2019/12/17 14:52:51 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	no_lenght_specifie(t_info *info, va_list va)
{
	int	value;

	if (!(info->flags ^ FLAGS_CHAR))
		value = (char)va_arg(va, int);
	else if (!(info->flags ^ FLAGS_SHORT))
		value = (short int)va_arg(va, int);
	else
	{
		value = va_arg(va, int);
		if (!(1 + (value >> 31) - (-value >> 31)))
		{
			value = -value;
			info->negative = 1;
		}
	}
	put_format(info, value);
	(void)va;
}

void  conv_type_integer(t_info *info, va_list va)
{
	long long	vlong_long;
	long		vlong;

	if (info->flags & FLAGS_LONG_LONG)
	{
		vlong_long = va_arg(va, long long);
		if (!(1 + (vlong_long >> 31) - (-vlong_long >> 31)))
		{
			info->negative = 1;
			vlong_long = -vlong_long;
		}
		put_format(info,  (unsigned long long)vlong_long);
	}
	else if (info->flags & FLAGS_LONG)
	{
		vlong = va_arg(va, long);
		if (!(1 + (vlong >> 31) - (-vlong >> 31)) && (info->negative = 1))
			vlong = 0 - vlong;
		put_format(info, (unsigned long long)vlong);
	}
	else
		no_lenght_specifie(info, va);
	(void)va;
}
