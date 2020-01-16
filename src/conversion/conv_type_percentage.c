/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_type_percentage.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 16:32:26 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/16 16:50:12 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_type_percentage(t_info *info, va_list va)
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
	(void)i;
}
