/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ignore_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:18:47 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/16 15:30:02 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ignore_0_when_left(t_info *info)
{
	if ((info->flags & FLAGS_LEFT))
	{
		info->flags &= ~(FLAGS_ZERO);
	}
}

void	ignore_0_when_precision(t_info *info)
{
	if ((info->flags & FLAGS_PRECISION) && (info->flags & FLAGS_ZERO))
		info->flags &= ~FLAGS_ZERO;
}
