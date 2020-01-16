/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_string_addr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:17:37 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/16 13:07:27 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	flags_left(t_info *info, char **p, size_t lenght)
{
	size_t	i;
	size_t	save_lenght;
	size_t	nb_space;
	char	c;

	if (info->flags & FLAGS_ZERO)
		c = '0';
	else
		c = ' ';
	i = 0;
	save_lenght = lenght;
	while (lenght)
	{
		fill_buf(info, 1, **p);
		(*p)++;
		lenght--;
	}
	lenght = save_lenght;
	if ((unsigned int)info->width > lenght)
	{
		nb_space = info->width - lenght;
		while (i < nb_space)
		{
			fill_buf(info, 1, c);
			i++;
		}
	}
}

static void	not_flags_left(t_info *info, char **p, size_t lenght)
{
	size_t	i;
	size_t	save_lenght;
	char	c;

	if (info->flags & FLAGS_ZERO)
		c = '0';
	else
		c = ' ';
	i = 0;
	save_lenght = lenght;
	if ((unsigned int)info->width > lenght)
	{
		fill_buf(info, info->width - save_lenght, c);
	}
	while (lenght)
	{
		fill_buf(info, 1, **p);
		lenght--;
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
		p = "(null)";
	lenght = ft_strlen(p);
	if (info->flags & FLAGS_PRECISION && lenght > info->precision)
	{
		lenght = info->precision;
		if (!info->precision && (info->flags & FLAGS_NEG_PREC))
			lenght = ft_strlen(p);
	}
	if ((info->flags & FLAGS_LEFT))
	{
		info->flags &= ~(FLAGS_ZERO);
		flags_left(info, &p, lenght);
	}
	else
	{
		not_flags_left(info, &p,lenght);
	}
	info->ret += write(1, info->buf, info->lenght);
}
