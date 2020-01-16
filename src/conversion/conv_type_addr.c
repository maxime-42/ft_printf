/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_type_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 16:38:09 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/16 16:40:49 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t	lenght_width_precision(t_info *info, unsigned long long addr,
size_t size_addr)
{
	size_t				total_size;

	total_size = size_addr;
	if ((info->flags & FLAGS_PRECISION) && info->precision > size_addr)
		total_size = info->precision;
	if (info->flags & FLAGS_WIDTH)
	{
		total_size += 2;
		if (!(info->flags & FLAGS_PRECISION) && !addr)
			total_size += 1;
	}
	return (total_size);
}

static void		no_flags_left(t_info *info, unsigned long long addr,
size_t size_addr, size_t total_size)
{
	put_width_in_buf(info, total_size);
	fill_buf(info, 1, '0');
	fill_buf(info, 1, 'x');
	if (!addr)
		size_addr = 0;
	put_precision_in_buf(info, size_addr);
	if ((info->flags & FLAGS_PRECISION) && addr == 0)
		;
	else
	{
		size_addr = ft_lenght_nbr(addr, info->base);
		if ((info->lenght + size_addr) >= BUF_SIZE)
			index_max_buf(info);
		ft_ntoa_base(addr, "0123456789abcdef", info->buf + info->lenght);
		info->lenght += size_addr;
	}
}

static void		flags_left(t_info *info, unsigned long long addr,
size_t size_addr, size_t total_size)
{
	size_t				tmp;

	fill_buf(info, 1, '0');
	fill_buf(info, 1, 'x');
	tmp = ft_lenght_nbr(addr, info->base);
	if ((info->lenght + tmp) >= BUF_SIZE)
	{
		index_max_buf(info);
	}
	put_precision_in_buf(info, size_addr);
	ft_ntoa_base(addr, "0123456789abcdef", info->buf + info->lenght);
	info->lenght += size_addr;
	put_width_in_buf(info, total_size);
}

void			conv_type_addr(t_info *info, va_list va)
{
	unsigned long long	addr;
	size_t				total_size;
	size_t				size_addr;

	size_addr = 0;
	addr = (unsigned long long)va_arg(va, char*);
	if (addr)
	{
		size_addr += ft_lenght_nbr(addr, info->base);
	}
	total_size = lenght_width_precision(info, addr, size_addr);
	if (info->flags & FLAGS_LEFT)
	{
		flags_left(info, addr, size_addr, total_size);
	}
	else
	{
		no_flags_left(info, addr, size_addr, total_size);
	}
	info->ret += write(1, info->buf, info->lenght);
}
