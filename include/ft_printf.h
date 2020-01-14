/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:54:05 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/13 17:51:08 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# define BUF_SIZE 64U
# define FLAGS_ZERO			(1U <<  0U)
# define FLAGS_LEFT			(1U <<  1U)
# define FLAGS_PLUS			(1U <<  2U)
# define FLAGS_SPACE		(1U <<  3U)
# define FLAGS_HASH			(1U <<  4U)
# define FLAGS_UPPERCASE	(1U <<  5U)
# define FLAGS_CHAR			(1U <<  6U)
# define FLAGS_SHORT		(1U <<  7U)
# define FLAGS_LONG			(1U <<  8U)
# define FLAGS_LONG_LONG	(1U <<  9U)
# define FLAGS_PRECISION	(1U << 10U)
# define FLAGS_WIDTH		(1U << 11U)
# define FLAGS_APOSTROPHE	(1U << 12U)
# define FLAGS_UNSIGNED		(1U << 13U)

typedef struct			s_info
{
	char				buf[BUF_SIZE];
	unsigned int		flags;
	unsigned int		precision;
	unsigned int		width;
	unsigned int		lenght;
	unsigned int		base;
	unsigned short int	negative;
	int					ret;
}						t_info;

typedef	struct			s_struct
{
  char				type;
  void				(*ptr)(t_info *info, va_list va);
}				t_struct;

int				ft_printf(const char *fmt, ...) __attribute__((format(printf, 1, 2)));
void				check_flags(const char **fmt, t_info *info);
void				check_width(const char **fmt, t_info *info, va_list va);
void				check_precision(const char **fmt, t_info *info, va_list va);
void				check_lenght_specifies(const char **fmt, t_info *info);
void				check_type(const char **fmt, t_info *info);
void				print_bits(unsigned int n);
void				put_precision_in_buf(t_info *info,  unsigned int size);
void				put_width_in_buf(t_info *info, unsigned int size);
void				handle_hash(t_info *info);
void				put_signe_in_buf(t_info *info);
void				find_conv_type(const char **fmt, t_info *info, va_list va);
void				convert_long(t_info *info, long value);
void				conv_type_integer(t_info *info, va_list va);
void				conv_type_string(t_info *info, va_list  va);
void				conv_type_addr(t_info *info, va_list  va);
//void				ntoa(t_info *info, unsigned long long value);
char				*ft_ntoa(long long n, char *base, char *p);
void				conv_type_c(t_info *info, va_list  va);
void				conv_type_percentage(t_info *info, va_list  va);
void				conv_type_n(t_info *info, va_list  va);
void				conv_type_float(t_info *info, va_list va);
void				fill_buf(t_info *info, size_t n, char c);
void				special_case_with_zero(t_info *info, unsigned long long value);
#endif
