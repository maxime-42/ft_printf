/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_hash_signe_space_in_buffer.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:29:17 by mkayumba          #+#    #+#             */
/*   Updated: 2019/12/03 16:09:00 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_hash(t_info *info)
{
	if (info->flags & FLAGS_HASH)
	{
		fill_buf(info, 1, '0');
		if (!(info->base ^ 16U) && !(info->flags & FLAGS_UPPERCASE))
			fill_buf(info, 1, 'x');
		else if (!(info->base ^ 16U) && (info->flags & FLAGS_UPPERCASE))
			fill_buf(info, 1, 'X');
		else if (!(info->base ^ 2U))
	  		fill_buf(info, 1, 'b');
	}
}

void	put_signe_in_buf(t_info *info)
{
	if (info->negative)
	{
		fill_buf(info, 1, '-');
	}
	else if (info->flags & FLAGS_PLUS)
	{
		fill_buf(info, 1, '+');
	}
}
