/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:08:03 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/16 16:49:25 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	put_format(t_info *info, unsigned long long value)
{
	unsigned int size;
	unsigned int total_size;

	size = ft_lenght_nbr(value, info->base);
	total_size = size;
	if ((info->flags & FLAGS_HASH))
		total_size += 2;
	if (!value)
		info->flags &= ~FLAGS_HASH;
	if (info->width)
		if (info->negative || (info->flags & (FLAGS_PLUS | FLAGS_SPACE)))
			info->width -= 1;
	if ((info->flags & FLAGS_LEFT))
	{
		integer_flags_left(info, value, size, total_size);
	}
	else
		integer_no_flags_left(info, value, size, total_size);
	info->ret += write(1, info->buf, info->lenght);
}

static	void	no_lenght_specifie(t_info *info, va_list va)
{
	int					value;
	unsigned long long	u_value;

	u_value = 0;
	if (!(info->flags ^ FLAGS_CHAR))
		value = (char)va_arg(va, int);
	else if (!(info->flags ^ FLAGS_SHORT))
		value = (short int)va_arg(va, int);
	else
	{
		if (info->flags & FLAGS_UNSIGNED)
			put_format(info, (unsigned long long)va_arg(va, unsigned int));
		else
		{
			value = va_arg(va, int);
			if (value < 0)
				info->negative = 1;
			u_value = conv_int_to_unsigned_longlong(value);
			put_format(info, u_value);
		}
		return ;
	}
	put_format(info, (unsigned long long)value);
	(void)va;
}

void			conv_type_integer(t_info *info, va_list va)
{
	long long	vlong_long;
	long		vlong;

	vlong = 0;
	ignore_0_when_left(info);
	ignore_0_when_precision(info);
	if (info->flags & FLAGS_LONG_LONG)
	{
		vlong_long = va_arg(va, long long);
		if (vlong_long < 0 && (info->negative = 1))
			vlong_long = -vlong_long;
		put_format(info, (unsigned long long)vlong_long);
	}
	else if (info->flags & FLAGS_LONG)
	{
		vlong = va_arg(va, long);
		if (vlong < 0 && (info->negative = 1))
			vlong = 0 - vlong;
		put_format(info, (unsigned long long)vlong);
	}
	else
		no_lenght_specifie(info, va);
}
