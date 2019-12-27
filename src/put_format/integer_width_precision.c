/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:19:01 by mkayumba          #+#    #+#             */
/*   Updated: 2019/12/27 14:43:58 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_precision_in_buf(t_info *info,  unsigned int size)
{
	if (info->flags & FLAGS_PRECISION)
	{
		info->flags &= ~FLAGS_ZERO;
		if (info->precision > size)
		{
			size = info->precision - size;
			fill_buf(info, size, '0');
		}
	}
}

void	put_width_in_buf(t_info *info, unsigned int size)
{
	if ((info->flags & FLAGS_SPACE))
		fill_buf(info,  1, ' ');
	if ((info->flags & FLAGS_ZERO) && (info->lenght < info->width))
	{
		if (info->width > size)
			fill_buf(info, info->width - size, '0');
	}
	else if (!(info->flags & FLAGS_LEFT) && !(info->flags & FLAGS_ZERO))
	{
		if (info->width > size)
			fill_buf(info, info->width - size, ' ');
	}
	else if (info->flags & FLAGS_LEFT)
	{
		if (info->width > size)
		{
			if (info->width > size)
				fill_buf(info, info->width - size, ' ');
		}
	}
}
