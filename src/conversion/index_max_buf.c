/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:33:31 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/14 17:37:21 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	index_max_buf(t_info *info)
{
	if (!(info->lenght ^ BUF_SIZE))
	{
		info->ret += write(1, info->buf, info->lenght);
		info->lenght = 0;
	}
}
