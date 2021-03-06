/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:13:08 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/16 17:28:55 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

static int		is_flags(const char **fmt)
{
	if (!(**fmt ^ '0') || !(**fmt ^ '-'))
		return (1);
	if (!(**fmt ^ '+') || !(**fmt ^ ' ') || !(**fmt ^ '#'))
		return (1);
	return (0);
}

void			check_flags(const char **fmt, t_info *info)
{
	while (is_flags(fmt))
	{
		if (!(**fmt ^ '0'))
		{
			info->flags |= FLAGS_ZERO;
		}
		else if (!(**fmt ^ '-'))
		{
			info->flags |= FLAGS_LEFT;
		}
		else if (!(**fmt ^ '+'))
		{
			info->flags |= FLAGS_PLUS;
		}
		else if (!(**fmt ^ ' '))
		{
			info->flags |= FLAGS_SPACE;
		}
		else if (!(**fmt ^ '#'))
		{
			info->flags |= FLAGS_HASH;
		}
		(*fmt)++;
	}
}

void			check_width(const char **fmt, t_info *info, va_list va)
{
	int	w;

	if (ft_isdigit(**fmt))
	{
		info->flags |= FLAGS_WIDTH;
		info->width = ft_atoi(*fmt);
		while (ft_isdigit(**fmt))
			(*fmt)++;
	}
	else if (!(**fmt ^ '*'))
	{
		w = va_arg(va, int);
		info->flags |= FLAGS_WIDTH;
		if (w < 0)
		{
			info->flags |= FLAGS_LEFT;
			info->width = (unsigned int)0 - w;
		}
		else
			info->width = (unsigned int)w;
		(*fmt)++;
	}
	(void)va;
}

void			check_precision(const char **fmt, t_info *info, va_list va)
{
	int	prec;

	if (!(**fmt ^ '.'))
	{
		(*fmt)++;
		info->flags |= FLAGS_PRECISION;
		if (ft_isdigit(**fmt))
		{
			info->precision = ft_atoi(*fmt);
			while (ft_isdigit(**fmt))
				(*fmt)++;
		}
		else if (!(**fmt ^ '*'))
		{
			prec = va_arg(va, int);
			if (prec >= 0)
				info->precision = (unsigned int)prec;
			else if (prec < 0)
				info->flags |= FLAGS_NEG_PREC;
			else
				info->precision = 0;
			(*fmt)++;
		}
	}
	(void)va;
}
