/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_type_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 16:38:09 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/10 18:16:49 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	flags_left(t_info *info, unsigned long long addr, size_t size_addr)
{
	size_t	size_width;

	fill_buf(info, 1, '0');
	fill_buf(info, 1, 'x');
	if (!(info->flags & FLAGS_PRECISION))
		ntoa(info, addr);
	if (info->width > size_addr)
	{
		size_width = info->width - size_addr;
		fill_buf(info, size_width, ' ');
	}
}

static	void	no_flags_left(t_info *info, unsigned long long addr, size_t size_addr)
{
	size_t	size_width;

	if (info->width > size_addr)
	{
		size_width = info->width - size_addr;
/* 		if ((info->flags & FLAGS_PRECISION) && info->) */
/* 		{ */
/* 			put_precision_in_buf(info, size_addr); */
/* 		} */
		fill_buf(info, size_width, ' ');
		fill_buf(info, 1, '0');
		fill_buf(info, 1, 'x');
		ntoa(info, addr);
	}
	else
	{
		fill_buf(info, 1, '0');
		fill_buf(info, 1, 'x');
		if (!(info->flags & FLAGS_PRECISION))
			ntoa(info, addr);
	}
}

void	conv_type_addr(t_info *info, va_list  va)
{
	unsigned long long addr;
	size_t				size_addr;

	size_addr = 2;
	addr = (unsigned long long)va_arg(va, char*);
	//if (addr)
		size_addr += ft_lenght_nbr(addr, info->base);
	printf("\nhellow size_addr = %zu | addr = %llu\n", size_addr, addr);
	//printf("\naddr = %llu | size = %zu\n", addr, size_addr);
	if ((info->flags & FLAGS_LEFT))
	{
/* 		printf("\nflags left\n"); */
		flags_left(info, addr, size_addr);
	}
	else
	{
/* 		printf("\nnonflags left\n"); */
		no_flags_left(info, addr, size_addr);
	}
	info->ret += write(1, info->buf, info->lenght);
}
