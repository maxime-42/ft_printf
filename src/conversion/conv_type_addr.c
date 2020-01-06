/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_type_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 16:38:09 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/06 12:52:53 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_type_addr(t_info *info, va_list  va)
{
	unsigned long long addr;
	size_t	i;

	i = 0;
	addr = (unsigned long long)va_arg(va, char*);
	info->buf[info->lenght++] = '0';
	info->buf[info->lenght++] = 'x';
	ntoa(info, addr);
	if ((info->flags & FLAGS_LEFT))
	{
		while (info->width >info->lenght && i++ < (info->width - info->lenght))
			info->ret += write(1, " ", 1);
	}
	info->ret += write(1, info->buf, info->lenght);
	if ((info->flags & FLAGS_LEFT))
		while (info->width >info->lenght && i++ < (info->width - info->lenght))
			info->ret += write(1, " ", 1);
}
