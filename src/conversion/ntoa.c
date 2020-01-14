/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ntoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:32:29 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/14 15:03:59 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apostrophe(t_info *info, int *p)
{
	if (!(*p % 3) && *p)
	{
		info->buf[info->lenght++] = '.';
	}
	else if (*p == 0)
		*p = 0;
	*p -= 1;
}

static void	lenght_max(t_info *info)
{
	if (!(info->lenght ^ BUF_SIZE))
	{
		info->ret += write(1, info->buf, info->lenght);
		info->lenght = 0;
	}
}


/* void	ntoa(t_info *info, unsigned long long value) */
/* { */
/* 	int		digit; */
/* 	static	int	index = 0; */

/* 	lenght_max(info); */
/* 	if (value >= info->base) */
/* 	{ */
/* 		index++; */
/* 		ntoa(info, value / info->base); */
/* 	} */
/* 	digit = value % info->base; */
/* 	if (digit < 10) */
/* 		info->buf[info->lenght++] = digit + '0'; */
/* 	else if (info->flags & FLAGS_UPPERCASE) */
/* 	{ */
/* 		//printf("\nMAJUSCULE\n"); */
/* 		//return ; */
/* 		info->buf[info->lenght++] = digit + 'A'- 10; */
/* 	} */
/* 	else */
/* 	{ */
/* 		//printf("\nminiscule\n"); */
/* 	info->buf[info->lenght++] = digit + 'a'- 10; */
/* 	} */
/* /\* 	if ((info->flags & FLAGS_APOSTROPHE)) *\/ */
/* /\* 		apostrophe(info, &index); *\/ */
/* } */
