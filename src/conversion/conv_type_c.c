/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:43:34 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/16 16:42:54 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	no_flags_left(t_info *info, char c, size_t size)
{
	put_width_in_buf(info, size);
	fill_buf(info, 1, c);
	(void)c;
	(void)size;
}

static void	flags_left(t_info *info, char c, size_t size)
{
	fill_buf(info, 1, c);
	put_width_in_buf(info, size);
	(void)c;
	(void)size;
}

void		conv_type_c(t_info *info, va_list va)
{
	char	c;
	size_t	size;

	size = 1;
	c = (char)va_arg(va, int);
	if ((info->flags & FLAGS_LEFT))
	{
		flags_left(info, c, size);
	}
	else
	{
		no_flags_left(info, c, size);
	}
	info->ret += write(1, info->buf, info->lenght);
	(void)c;
	(void)size;
}
