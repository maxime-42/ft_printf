/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_int_to_unsigned_longlong.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:10:12 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/16 15:11:50 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	conv_int_to_unsigned_longlong(int int_value)
{
		unsigned long long u_value;

		if (int_value < 0)
		{
			u_value = (unsigned long long)int_value * -1;
		}
		else
			u_value = (unsigned long long)int_value;
		return (u_value);
}
