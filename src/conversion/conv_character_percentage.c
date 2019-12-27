/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:43:34 by mkayumba          #+#    #+#             */
/*   Updated: 2019/12/27 14:50:45 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_type_c(t_info *info, va_list  va)
{
	char character;
	size_t	i;

	i = 0;
	character = (char)va_arg(va, int);
	info->lenght = 1;
	if (!(info->flags & FLAGS_LEFT))
	{
		while (info->width >info->lenght && i++ < (info->width - info->lenght))
			info->ret += write(1, " ", 1);
	}
	info->ret += write(1, &character, 1);
	if ((info->flags & FLAGS_LEFT))
		while (info->width >info->lenght && i++ < (info->width - info->lenght))
			info->ret += write(1, " ", 1);
}

void	conv_type_percentage(t_info *info, va_list  va)
{
	size_t	i;

	i = 0;
	info->lenght = 0;
	if (info->flags & FLAGS_ZERO && info->flags & FLAGS_LEFT)
		info->flags &= ~FLAGS_ZERO;
	if (!(info->flags & FLAGS_LEFT))
	{
			put_width_in_buf(info, 1);
			info->buf[info->lenght++] = '%';
	}
	if ((info->flags & FLAGS_LEFT))
	{
			info->buf[info->lenght++] = '%';
			put_width_in_buf(info, 1);
	}
	info->ret += write(1, info->buf, info->lenght);
	(void)va;
}

void	conv_type_n(t_info *info, va_list  va)
{
	int *p;

	p = va_arg(va, int*);
	*p = info->ret;
}
