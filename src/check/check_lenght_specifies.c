/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght_specifies.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:00:58 by mkayumba          #+#    #+#             */
/*   Updated: 2019/11/27 12:29:24 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>
#include <stdint.h>

static void	specifie_l_ll(const char **fmt, t_info *info)
{
	info->flags |=  FLAGS_LONG;
	if (!(**fmt ^ 'l') && (*fmt)++)
		info->flags |=  FLAGS_LONG_LONG;
}

static void specifie_h_hh(const char **fmt, t_info *info)
{
	info->flags |= FLAGS_SHORT;
	if (!(**fmt ^ 'h') && (*fmt)++)
		info->flags |=  FLAGS_CHAR;
}

void	check_lenght_specifies(const char **fmt, t_info *info)
{
	if (!(**fmt ^ 'l') && (*fmt)++)
		specifie_l_ll(fmt, info);
	else if (!(**fmt ^ 'h') && (*fmt)++)
		specifie_h_hh(fmt, info);
	else if (!(**fmt ^ 't') && (*fmt)++)
	{
		if (!(sizeof(ptrdiff_t) ^ sizeof(long)))
			info->flags |=  FLAGS_LONG;
		else
			info->flags |=  FLAGS_LONG_LONG;
	}
	else if (!(**fmt ^ 'j') && (*fmt)++)
	{
		if (sizeof(intmax_t) == sizeof(long))
			info->flags |=  FLAGS_LONG;
		else
			info->flags |=  FLAGS_LONG_LONG;
	}
	else if (!(**fmt ^ 'z') && (*fmt)++)
	{
		if (sizeof(size_t) == sizeof(long))
			info->flags |=  FLAGS_LONG;
		else
			info->flags |=  FLAGS_LONG_LONG;
	}
}
