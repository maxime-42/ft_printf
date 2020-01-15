/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:43:34 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/15 17:53:53 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_type_c(t_info *info, va_list  va)
{
	char character;
	size_t	i;
	size_t	size_c;

	i = 0;
	size_c = 1;
	character = (char)va_arg(va, int);
	//info->lenght = 1;
	if (!(info->flags & FLAGS_LEFT))
	{
		while (info->width >info->lenght && i++ < (info->width - info->lenght))
			info->ret += write(1, " ", 1);
	}
	info->ret += write(1, &character, 1);
	if ((info->flags & FLAGS_LEFT))
		while (info->width >info->lenght && i++ < (info->width - info->lenght))
			info->ret += write(1, " ", 1);
}

/* void	conv_type_c(t_info *info, va_list  va) */
/* { */
/* 	char character; */
/* 	size_t	i; */

/* 	i = 0; */
/* 	character = (char)va_arg(va, int); */
/* 	info->lenght = 1; */
/* 	if (!(info->flags & FLAGS_LEFT)) */
/* 	{ */
/* 		while (info->width >info->lenght && i++ < (info->width - info->lenght)) */
/* 			info->ret += write(1, " ", 1); */
/* 	} */
/* 	info->ret += write(1, &character, 1); */
/* 	if ((info->flags & FLAGS_LEFT)) */
/* 		while (info->width >info->lenght && i++ < (info->width - info->lenght)) */
/* 			info->ret += write(1, " ", 1); */
/* } */
