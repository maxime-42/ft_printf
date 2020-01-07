/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:08:03 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/07 15:12:42 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	no_flags_left(t_info *info, unsigned long long value,
			      unsigned int size, unsigned total_size)
{
	if (info->precision > size)
	{
		total_size = info->precision;
	}
	if ((info->flags & FLAGS_ZERO) && info->negative)
		put_signe_in_buf(info);
	put_width_in_buf(info, total_size);
	if (!(info->flags & FLAGS_ZERO))
		put_signe_in_buf(info);
	handle_hash(info);
	put_precision_in_buf(info, size);
	ntoa(info, value);
	info->ret += write(1, info->buf, info->lenght);
}

static void	put_format(t_info *info, unsigned long long value)
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
		handle_hash(info);
		put_signe_in_buf(info);
		put_precision_in_buf(info, size);
		ntoa(info, value);
		if (info->precision > size)
			total_size = info->precision;
		put_width_in_buf(info, total_size);
		info->ret += write(1, info->buf, info->lenght);
	}
	else
		no_flags_left(info, value, size, total_size);
}

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

	if ((info->flags & FLAGS_PRECISION) && (info->flags & FLAGS_ZERO))
	{
		printf("\nhellow\n");
		//info->flags &= ~FLAGS_ZERO;
		info->flags &= ~FLAGS_ZERO;
		printf("salut\n");
	}
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
