/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:19:01 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/06 16:43:08 by mkayumba         ###   ########.fr       */
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

static void width_neg_nb(t_info *info, unsigned int size)
{
	if (info->width > size)
	{
		if (info->negative)
		{
			info->lenght -= 1;
			fill_buf(info, info->width - size, ' ');
			fill_buf(info, 1, '-');
		}
		else
			fill_buf(info, info->width - size, ' ');
	}
}

void	put_width_in_buf(t_info *info, unsigned int size)
{
	if ((info->flags & FLAGS_SPACE))
	{
		fill_buf(info,  1, ' ');
	}
	if ((info->flags & FLAGS_ZERO) && (info->lenght < info->width) && !(info->flags & FLAGS_PRECISION))
	{
		printf("salut width = %u\n", info->width);
		if (info->width > size)
			fill_buf(info, info->width - size, '0');
	}
	else if (!(info->flags & FLAGS_LEFT) && !(info->flags & FLAGS_ZERO))
	{
	printf("salut width = %u\n", info->width);
		if (info->width > size)
		{
			//fill_buf(info, info->width - size, ' ');
			width_neg_nb(info, size);
		}
	}
	else if (info->flags & FLAGS_LEFT)
	{
	printf("salut width = %u\n", info->width);
		if (info->width > size)
		{
			//fill_buf(info, info->width - size, ' ');
			width_neg_nb(info, size);
		}
	}
}
