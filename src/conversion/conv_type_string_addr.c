/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_string_addr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:17:37 by mkayumba          #+#    #+#             */
/*   Updated: 2019/12/19 17:43:57 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_type_string(t_info *info, va_list  va)
{
	char *p;
	size_t	lenght;
	size_t	i;

	i = 0;
	p = va_arg(va, char*);
	if (!p)
	{
		info->ret += write(1, "(null)", 6);
		return ;
	}
	lenght = ft_strlen(p);
	if ((info->flags & FLAGS_PRECISION))
		if (info->precision < lenght)
			lenght = info->precision;
	if (!(info->flags & FLAGS_LEFT))
		while (info->width > lenght && i++ < (info->width - lenght))
			info->ret += write(1, " ", 1);
	info->ret += write(1, p, lenght);
	if ((info->flags & FLAGS_LEFT))
		while (lenght < info->width)
		{
			info->ret += write(1, " ", 1);
			lenght++;
		}
}

void	conv_type_addr(t_info *info, va_list  va)
{
	unsigned long long addr;
	size_t	i;

	i = 0;
	addr = (unsigned long long)va_arg(va, char*);
	info->buf[info->lenght++] = '0';
	info->buf[info->lenght++] = 'x';
	ntoa(info, addr);
	if (!(info->flags & FLAGS_LEFT))
	{
		while (info->width >info->lenght && i++ < (info->width - info->lenght))
			info->ret += write(1, " ", 1);
	}
	info->ret += write(1, info->buf, info->lenght);
	if ((info->flags & FLAGS_LEFT))
		while (info->width >info->lenght && i++ < (info->width - info->lenght))
			info->ret += write(1, " ", 1);
}
