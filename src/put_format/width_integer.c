/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:30:41 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/16 11:15:36 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void space(t_info *info, unsigned int size)
{
	if (info->negative && !(info->flags & FLAGS_LEFT))
	{
		if (info->lenght > 0)
			info->lenght -= 1;
		fill_buf(info, size, ' ');
	}
	else
		fill_buf(info, size, ' ');
}

void	put_width_in_buf(t_info *info, unsigned int size)
{
	if ((unsigned int)info->width > size)
	{
		if ((info->flags & FLAGS_SPACE))
		{
			space(info, 1);
		}
		else if ((info->flags & FLAGS_ZERO))
		{
			fill_buf(info, info->width - size, '0');
		}
		else if (!(info->flags & FLAGS_LEFT) && !(info->flags & FLAGS_ZERO))
		{
			space(info, info->width - size);

		}
		else if (info->flags & FLAGS_LEFT)
		{
			space(info, info->width - size);
		}
	}
}
