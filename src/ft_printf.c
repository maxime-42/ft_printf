/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:52:13 by mkayumba          #+#    #+#             */
/*   Updated: 2019/12/19 16:26:16 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_bits(unsigned int n)
{
	if (n > 1)
		print_bits(n >> 1);
	if (n & 1 << 0)
		write(1, "1", 1);
	else
		write(1, "0", 1);

}

static void	init_struct(t_info *info)
{
	info->base = 0;
	info->flags = 0;
	info->width = 0;
	info->negative = 0;
	info->lenght = 0;
	info->precision = 0;
}

static int	_vsnprintf(const char *fmt, va_list va)
{
	t_info		info;

	info.ret = 0;
	while (*fmt)
	{
		init_struct(&info);
		while  ((*fmt && *fmt ^ '%') && info.lenght < BUF_SIZE)
			info.buf[info.lenght++] = *fmt++;
		if (!(info.lenght ^ BUF_SIZE))
		{
			info.ret += write(1, &info.buf, info.lenght);
			init_struct(&info);
		}
		if  (!(*fmt ^ '%'))
		{
			fmt++;
			check_flags(&fmt, &info);
			check_width(&fmt, &info, va);
			check_precision(&fmt, &info, va);
			check_lenght_specifies(&fmt, &info);
			check_type(&fmt, &info);
			find_conv_type(&fmt, &info, va);
		}
		else
			info.ret += write(1, &info.buf, info.lenght);
	}
	(void) va;
	return (info.ret);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	va;
	int ret;

	va_start(va, fmt);
	ret = _vsnprintf(fmt, va);
	va_end(va);
	(void) va;
	return (ret);
}
