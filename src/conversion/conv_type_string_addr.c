/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_string_addr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:17:37 by mkayumba          #+#    #+#             */
/*   Updated: 2019/12/27 16:38:36 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static flags_left(t_info *info, char **p, size_t lenght)
{
	size_t	i;
	size_t	save_lenght;

	i = 0;
	save_lenght = lenght;
	while (lenght)
	{
		fill_buf(info, 1, **p);
		(*p)++;
		lenght--;
	}
	lenght = save_lenght;
	if (info->width > lenght)
	{
		while (i < (info->width - lenght))
		{
			fill_buf(info, 1, ' ');
			i++;
		}
	}
}

static not_flags_left(t_info *info, char **p, size_t lenght)
{
	size_t	i;
	
	i = 0;
	while (lenght < info->width)
		fill_buf(info, info->width - save_lenght, ' ')
	while (lenght)
	{
		fill_buf(info, 1, **p);
		(*p)++;
	}

}

void	conv_type_string(t_info *info, va_list  va)
{
	char *p;
	size_t	lenght;
	size_t	i;

	i = 0;
	p = va_arg(va, char*);
	if (!p)
	{
		info->ret += write(1, "(null)", 6);
		return ;
	}
	lenght = ft_strlen(p);
	if (info->flags & FLAGS_PRECISION && info->precision < lenght)
	{
		lenght = info->precision;
	}
	if ((info->flags & FLAGS_LEFT))
		flags_left(info, &p, lenght);
	else
	{
		not_flags_left(info, &p,lenght);
	}
	info->ret += write(1, info->buf, info->lenght);
}
