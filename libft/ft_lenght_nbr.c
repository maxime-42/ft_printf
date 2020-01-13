/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenght_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:16:45 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/13 17:10:06 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_lenght_nbr(long long nbr, unsigned int base)
{
	unsigned int	i;

	i = 0;
	if (!nbr)
		i = 1;
	while (nbr)
	{
		nbr = nbr / base;
		i++;
	}
	return (i);
}
