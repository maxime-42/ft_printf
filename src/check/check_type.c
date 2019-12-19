/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:37:44 by mkayumba          #+#    #+#             */
/*   Updated: 2019/12/03 17:20:02 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_type(const char **fmt, t_info *info)
{
 	if (!(**fmt ^ 'x') || !(**fmt ^ 'X') || !(**fmt ^ 'o') ||
		!(**fmt ^ 'b') || !(**fmt ^ 'i') || !(**fmt ^ 'd') ||
	    !(**fmt ^ 'p') || !(**fmt ^ 'f') || !(**fmt ^ 'u') || !(**fmt ^ (char)39))
	{
		if (!(**fmt ^ 'x') || !(**fmt ^ 'X') || !(**fmt ^ 'p'))
		{
			info->base = 16U;
			if (!(**fmt ^ 'X'))
				info->flags |= FLAGS_UPPERCASE;
		}
		else if (!(**fmt ^ 'o'))
			info->base =  8U;
		else if (!(**fmt ^ 'b'))
			info->base =  2U;
		else
		{
			if (!(**fmt ^ (char)39))
			{
				info->flags |= FLAGS_APOSTROPHE;
			}
			info->base = 10U;
			info->flags &= ~FLAGS_HASH;
		}
	}
	if (**fmt != 'i' && **fmt != 'd')
		info->flags &= ~(FLAGS_PLUS | FLAGS_SPACE);
}
