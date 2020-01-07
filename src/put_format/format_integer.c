/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:12:28 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/07 15:00:47 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
this file it is not user

 */
/* #include "ft_printf.h" */

/* static void	no_flags_left(t_info *info, unsigned long long value, */
/* 			      unsigned int size, unsigned total_size) */
/* { */
/* 	if (info->precision > size) */
/* 	{ */
/* 		total_size = (info->precision - size) + size; */
/* 	} */
/* 	if ((info->flags & FLAGS_ZERO) && info->negative) */
/* 		put_signe_in_buf(info); */
/* 	put_width_in_buf(info, total_size); */
/* 	if (!(info->flags & FLAGS_ZERO)) */
/* 		put_signe_in_buf(info); */
/* 	handle_hash(info); */
/* 	put_precision_in_buf(info, size); */
/* 	ntoa(info, value); */
/* 	info->ret += write(1, info->buf, info->lenght); */
/* } */

/* void	put_format(t_info *info, unsigned long long value) */
/* { */
/* 	unsigned int size; */
/* 	unsigned int total_size; */

/* 	size = ft_lenght_nbr(value, info->base); */
/* 	total_size = size; */
/* 	if ((info->flags & FLAGS_HASH)) */
/* 		total_size += 2; */
/*  	if (!value) */
/* 		info->flags &= ~FLAGS_HASH; */
/* 	if (info->width) */
/* 		if (info->negative || (info->flags & (FLAGS_PLUS | FLAGS_SPACE))) */
/* 			info->width -= 1; */
/* 	if ((info->flags & FLAGS_LEFT)) */
/* 	{ */
/* 		handle_hash(info); */
/* 		put_signe_in_buf(info); */
/* 		put_precision_in_buf(info, size); */
/* 		ntoa(info, value); */
/* 		if (info->precision > size) */
/* 			total_size = info->precision; */
/* 		put_width_in_buf(info, total_size); */
/* 		info->ret += write(1, info->buf, info->lenght); */
/* 	} */
/* 	else */
/* 		no_flags_left(info, value, size, total_size); */
/* } */
