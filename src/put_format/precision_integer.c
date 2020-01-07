/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:19:01 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/07 14:38:48 by mkayumba         ###   ########.fr       */
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
