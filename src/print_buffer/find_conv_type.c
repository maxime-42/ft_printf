/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:09:46 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/07 15:13:05 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	g_array[] = {
  {'i', &conv_type_integer},
  {'d', &conv_type_integer},
  {'u', &conv_type_integer},
  {'X', &conv_type_integer},
  {'x', &conv_type_integer},
  {'o', &conv_type_integer},
  {'s', &conv_type_string},
  {'p', &conv_type_addr},
  {'c', &conv_type_c},
  {'%', &conv_type_percentage},
  {'n', &conv_type_n},
  {'f', &conv_type_float},
  {0, 0},
};

void	find_conv_type(const char **fmt, t_info *info, va_list va)
{
	int	i;

	i = -1;
	if ((info->flags & FLAGS_APOSTROPHE) && !(**fmt ^ (char)39))
	{
		(*fmt)++;
	}
	while (g_array[++i].type)
	{
		if (!(g_array[i].type ^ **fmt))
		{
			g_array[i].ptr(info, va);
		}
	}
	if (**fmt)
		(*fmt)++;
	(void)va;
}
