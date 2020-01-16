/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:53:47 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/16 16:44:10 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <float.h>

static void	conv_value(t_info *info, double nb)
{
	unsigned long long	integer;
	unsigned long long	i;
	unsigned long long	tmp;

	i = 0;
	ntoa(info, (unsigned long long)nb);
	if (i < info->precision)
		info->buf[info->lenght++] = '.';
	while (i < info->precision)
	{
		integer = (unsigned long long)nb;
		tmp = (unsigned long long)(nb * 10) - (integer * 10);
		info->buf[info->lenght++] = (char)tmp + '0';
		nb *= 10;
		if (!(info->lenght ^ BUF_SIZE))
		{
			info->ret += write(1, info->buf, info->lenght);
			info->lenght = 0;
		}
		i++;
	}
}

static void	no_flags_left(t_info *info, double value, unsigned int total_size)
{
	if ((info->flags & FLAGS_ZERO) && info->negative)
		put_signe_in_buf(info);
	put_width_in_buf(info, total_size);
	if (!(info->flags & FLAGS_ZERO))
		put_signe_in_buf(info);
	conv_value(info, value);
	info->ret += write(1, info->buf, info->lenght);
	(void)info;
	(void)value;
}

static void	flags_left(t_info *info, double value, unsigned int total_size)
{
	put_signe_in_buf(info);
	conv_value(info, value);
	put_width_in_buf(info, total_size);
	info->ret += write(1, info->buf, info->lenght);
	(void)info;
	(void)value;
}

void		conv_type_float(t_info *info, va_list va)
{
	double		value;
	unsigned	total_size;

	value = va_arg(va, double);
	if (value < DBL_MIN || value > DBL_MAX)
	{
		info->ret += write(1, "inf", 3);
		return ;
	}
	if (value < 0)
	{
		value = -value;
		info->negative = 1;
	}
	if (info->width)
		if (info->negative || (info->flags & (FLAGS_PLUS | FLAGS_SPACE)))
			info->width -= 1;
	if (!(info->flags & FLAGS_PRECISION))
		info->precision = 6;
	total_size = info->precision + ft_lenght_nbr(value, info->base) + 1;
	if (!(info->flags & FLAGS_LEFT))
		no_flags_left(info, value, total_size);
	else if ((info->flags & FLAGS_LEFT))
		flags_left(info, value, total_size);
	(void)va;
}
