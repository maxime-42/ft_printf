/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_left_or_no_flags_left.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:34:01 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/16 15:47:08 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	integer_no_flags_left(t_info *info, unsigned long long value,
			      unsigned int size, unsigned total_size)
{
	if (info->precision > size)
	{
		total_size = info->precision;
	}
	if ((info->flags & FLAGS_ZERO) && info->negative)
		put_signe_in_buf(info);
	put_width_in_buf(info, total_size);
	if (!(info->flags & FLAGS_ZERO))
	{
		put_signe_in_buf(info);
	}
	handle_hash(info);
	put_precision_in_buf(info, size);
	ntoa(info, value);
	special_case_with_zero(info, value);
}

void	integer_flags_left(t_info *info, unsigned long long value, 
unsigned int size, unsigned total_size)
{
	handle_hash(info);
	put_signe_in_buf(info);
	put_precision_in_buf(info, size);
	ntoa(info, value);
	special_case_with_zero(info, value);
	if (info->precision > size)
		total_size = info->precision;
	put_width_in_buf(info, total_size);
}
