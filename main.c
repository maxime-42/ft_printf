/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkayumba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:46:47 by mkayumba          #+#    #+#             */
/*   Updated: 2020/01/06 15:43:03 by mkayumba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"
#include <stdio.h>
#include <math.h>
#include <locale.h>


int main(void)
{
	int i = 0;
	int j = 0;

	printf("---------------------------------------------------------\n");
	i = printf("%010.5d", -216);
	printf("\nretour officiel   : %d\n", i);
	fflush(stdout);
	j =  ft_printf("%010.5d", -216);
	printf("\nretour non officiel   : %d\n", j);
	printf("---------------------------------------------------------\n");
}
