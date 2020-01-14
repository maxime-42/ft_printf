/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_type_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 16:38:09 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/13 20:24:59 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

static void	no_flags_left( t_info *info, unsigned long long addr, size_t size_addr)
{
	size_t	total_size;

	total_size = size_addr;
	if ((info->flags & FLAGS_PRECISION) && info->precision > size_addr)
		total_size = info->precision;
	if (info->flags & FLAGS_WIDTH)
	{
		total_size += 2;
		if (!(info->flags & FLAGS_PRECISION) && !addr)
		{
			total_size += 1;
		}
		put_width_in_buf(info, total_size);
	}
	fill_buf(info, 1, '0');
	fill_buf(info, 1, 'x');
	if (!addr)
		size_addr = 0;
	put_precision_in_buf(info,  size_addr);
	if ((info->flags & FLAGS_PRECISION) && addr == 0)
		;
	else
		ntoa(info, addr);
}

void	conv_type_addr(t_info *info, va_list  va)
{
	unsigned long long addr;
	size_t	i;
	size_t	size_addr;

	i = 0;
	//size_addr = 2;
	size_addr = 0;
	//printf("\ninfo->base = %u\n", info->base);
	addr = (unsigned long long)va_arg(va, char*);
	if (addr)
	{
		size_addr += ft_lenght_nbr(addr, info->base);
	}
	no_flags_left(info, addr, size_addr);
	info->ret += write(1, info->buf, info->lenght);
}
