/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenght_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:16:45 by mkayumba          #+#    #+#             */
/*   Updated: 2019/11/29 15:17:43 by mkayumba         ###   ########.fr       */
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
